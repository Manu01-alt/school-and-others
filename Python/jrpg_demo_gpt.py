# jrpg_demo.py
import pygame, sys, random, math
from pygame.locals import *

pygame.init()
FONT = pygame.font.SysFont("consolas", 16)
BIGFONT = pygame.font.SysFont("consolas", 22)

# ---------- SETTINGS FINESTRA ------------
WIDTH, HEIGHT = 1100, 700
WIN = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("JRPG Turn-Based Demo")

# ---------- UTILS ------------
def ceil(x): return math.ceil(x)
def clamp(v, a, b): return max(a, min(b, v))

# ---------- STATI E CLASSI ------------
class Status:
    def __init__(self):
        self.stunned = 0
        self.taunt = 0
        self.marked = False
        self.damage_buff_turns = 0
        self.damage_buff_amount = 0.0
        self.attack_down_turns = 0
        self.slow_turns = 0
    def tick(self):
        if self.stunned > 0: self.stunned -= 1
        if self.taunt > 0: self.taunt -= 1
        if self.damage_buff_turns > 0: self.damage_buff_turns -= 1
        if self.attack_down_turns > 0: self.attack_down_turns -= 1
        if self.slow_turns > 0: self.slow_turns -= 1

class Character:
    def __init__(self, name, role, max_hp, max_mana, color):
        self.name = name
        self.role = role
        self.max_hp = max_hp
        self.hp = max_hp
        self.max_mana = max_mana
        self.mana = max_mana
        self.color = color
        self.alive = True
        self.status = Status()
        self.next_damage_multiplier = 1.0
    def take_damage(self, amount):
        amount = ceil(amount)
        self.hp -= amount
        if self.hp <= 0:
            self.hp = 0
            self.alive = False
        return amount
    def heal(self, amount):
        amount = ceil(amount)
        self.hp = clamp(self.hp + amount, 0, self.max_hp)
        if self.hp > 0:
            self.alive = True
        return amount
    def use_mana(self, cost):
        self.mana = clamp(self.mana - cost, 0, self.max_mana)
    def gain_mana(self, amt):
        self.mana = clamp(self.mana + amt, 0, self.max_mana)
    def tick(self):
        self.status.tick()
        if self.hp <= 0:
            self.alive = False

class Enemy(Character):
    def __init__(self, name, max_hp, attack_pct, color):
        super().__init__(name, "Enemy", max_hp, 0, color)
        self.attack_pct = attack_pct
    def choose_target(self, party):
        taunted = [p for p in party if p.status.taunt > 0 and p.alive]
        if taunted:
            return taunted[0]
        alive = [p for p in party if p.alive]
        if not alive:
            return None
        return random.choice(alive)

# ---------- CREAZIONE PERSONAGGI/NEMICI ------------
mage = Character("Aldren", "Mago", 420, 200, (100,160,255))
warrior = Character("Tharok", "Guerriero", 600, 120, (200,80,80))
archer = Character("Lyra", "Arciere", 360, 160, (80,200,120))
rogue = Character("Brug", "Predone", 700, 140, (200,170,90))
party = [mage, warrior, archer, rogue]

enemies = [
    Enemy("Goblin A", 150, 0.12, (160,160,80)),
    Enemy("Goblin B", 150, 0.12, (160,160,80)),
    Enemy("Scout", 75, 0.10, (180,140,100)),
    Enemy("Ogre", 250, 0.18, (120,80,40))
]

# ---------- BILANCIAMENTO & COSTI ------------
CRIT_CHANCE = 0.35
COST = {
    "mage_boost": 20, "mage_slow": 25, "mage_heal": 30, "mage_res": 40,
    "war_normal": 0, "war_heavy": 40, "war_mark": 20, "war_selfbuff": 25,
    "arch_normal": 0, "arch_two": 25, "arch_gravity": 30, "arch_ult": None,
    "rog_taunt": 20, "rog_stun": 25, "rog_partybuff": 35, "rog_ult": None
}
NORMAL_ATTACK_PERCENT = 0.12
NORMAL_MANA_RECOVERY = {"Mago": 15, "Guerriero": 20, "Arciere": 18, "Predone": 12}

# ---------- ABILITÀ ------------
def mage_boost(caster, party_members):
    cost = COST["mage_boost"]
    if caster.mana < cost:
        return "Mana insufficiente!"
    caster.use_mana(cost)
    for p in party_members:
        p.status.damage_buff_turns = 3
        p.status.damage_buff_amount = 0.44
    return f"{caster.name} lancia 'Luce Arcana' → Buff +44% (3 turni)."

def mage_slow(caster, enemies_list):
    cost = COST["mage_slow"]
    if caster.mana < cost:
        return "Mana insufficiente!"
    caster.use_mana(cost)
    messages = []
    for e in enemies_list:
        if not e.alive: continue
        crit = random.random() < CRIT_CHANCE
        slow_amount = 2 if crit else 1
        e.status.slow_turns += slow_amount
        messages.append(f"{e.name} rallentato di {slow_amount} turni{' (CRIT)' if crit else ''}")
    return f"{caster.name} usa 'Vento Gelido'. " + "; ".join(messages)

def mage_heal(caster, target):
    cost = COST["mage_heal"]
    if caster.mana < cost:
        return "Mana insufficiente!"
    caster.use_mana(cost)
    crit = random.random() < CRIT_CHANCE
    percent = 0.80 if crit else 0.55
    amount = target.max_hp * percent
    healed = target.heal(amount)
    return f"{caster.name} cura {target.name} per {ceil(healed)} HP{' (CRIT)' if crit else ''}."

def mage_resurrect(caster, down_target):
    cost = COST["mage_res"]
    if caster.mana < cost:
        return "Mana insufficiente!"
    if down_target.alive:
        return f"{down_target.name} è già vivo."
    caster.use_mana(cost)
    revive_hp = ceil(down_target.max_hp * 0.30)
    down_target.hp = revive_hp
    down_target.alive = True
    mage_loss = ceil(caster.max_hp * 0.10)
    caster.take_damage(mage_loss)
    return f"{caster.name} resuscita {down_target.name} con {revive_hp} HP ma perde {mage_loss} HP."

def warrior_normal(attacker, target):
    dmg = target.max_hp * 0.35
    mult = 1.0
    if attacker.status.damage_buff_turns > 0:
        mult += attacker.status.damage_buff_amount
    damage = dmg * mult
    if target.status.marked:
        damage *= 2
        target.status.marked = False
    dealt = target.take_damage(damage)
    attacker.gain_mana(NORMAL_MANA_RECOVERY[attacker.role])
    return f"{attacker.name} colpisce {target.name} per {dealt} HP."

def warrior_heavy(attacker, target):
    cost = COST["war_heavy"]
    if attacker.mana < cost:
        return "Mana insufficiente!"
    attacker.use_mana(cost)
    dmg = target.max_hp * 0.75
    if attacker.status.damage_buff_turns > 0:
        dmg *= (1 + attacker.status.damage_buff_amount)
    if target.status.marked:
        dmg *= 2
        target.status.marked = False
    dealt = target.take_damage(dmg)
    return f"{attacker.name} esegue 'Colpo Distruttore' su {target.name} per {dealt} HP."

def warrior_mark(attacker, target):
    cost = COST["war_mark"]
    if attacker.mana < cost:
        return "Mana insufficiente!"
    attacker.use_mana(cost)
    target.status.marked = True
    return f"{attacker.name} marchia {target.name} (prossimo danno x2)."

def warrior_selfbuff(attacker):
    cost = COST["war_selfbuff"]
    if attacker.mana < cost:
        return "Mana insufficiente!"
    attacker.use_mana(cost)
    attacker.status.damage_buff_turns = 3
    attacker.status.damage_buff_amount = 0.25
    return f"{attacker.name} si potenzia (+25% danno per 3 turni)."

def archer_aoe(attacker, enemies_list):
    messages = []
    for e in enemies_list:
        if not e.alive: continue
        dmg = e.max_hp * 0.15
        if attacker.status.damage_buff_turns > 0:
            dmg *= (1 + attacker.status.damage_buff_amount)
        if e.status.marked:
            dmg *= 2
            e.status.marked = False
        dealt = e.take_damage(dmg)
        messages.append(f"{e.name} -{dealt}")
    attacker.gain_mana(NORMAL_MANA_RECOVERY[attacker.role])
    return f"{attacker.name} esegue 'Pioggia di Frecce': " + "; ".join(messages)

def archer_two(attacker, enemies_list):
    # enemies_list is expected to be the selected list (1..2 items)
    target_enemies = [e for e in enemies_list if e.alive][:2]
    if not target_enemies:
        return "Nessun bersaglio valido."
    messages = []
    for e in target_enemies:
        dmg = e.max_hp * 0.30
        if attacker.status.damage_buff_turns > 0:
            dmg *= (1 + attacker.status.damage_buff_amount)
        if e.status.marked:
            dmg *= 2
            e.status.marked = False
        dealt = e.take_damage(dmg)
        messages.append(f"{e.name} -{dealt}")
    return f"{attacker.name} usa 'Doppia Mira': " + "; ".join(messages)

def archer_gravity(attacker, enemies_list):
    cost = COST["arch_gravity"]
    if attacker.mana < cost:
        return "Mana insufficiente!"
    attacker.use_mana(cost)
    for e in enemies_list:
        if not e.alive: continue
        e.status.attack_down_turns = max(e.status.attack_down_turns, 1)
    return f"{attacker.name} lancia 'Freccia Gravità' - attacchi nemici -50% per 1 turno."

def archer_ult(attacker, target):
    cost = attacker.mana
    if cost <= 0:
        return "Mana insufficiente!"
    attacker.use_mana(cost)
    dmg = target.max_hp * 0.80
    if attacker.status.damage_buff_turns > 0:
        dmg *= (1 + attacker.status.damage_buff_amount)
    if target.status.marked:
        dmg *= 2
        target.status.marked = False
    dealt = target.take_damage(dmg)
    return f"{attacker.name} usa 'Alba Infernale' su {target.name} per {dealt} HP (tutto il mana consumato)."

def rogue_taunt(attacker):
    cost = COST["rog_taunt"]
    if attacker.mana < cost:
        return "Mana insufficiente!"
    attacker.use_mana(cost)
    attacker.status.taunt = 2
    return f"{attacker.name} provoca i nemici (taunt 2 turni)."

def rogue_stun(attacker, target):
    cost = COST["rog_stun"]
    if attacker.mana < cost:
        return "Mana insufficiente!"
    attacker.use_mana(cost)
    target.status.stunned = max(target.status.stunned, 1)
    return f"{attacker.name} stordisce {target.name} per 1 turno."

def rogue_partybuff(attacker, party_members):
    cost = COST["rog_partybuff"]
    if attacker.mana < cost:
        return "Mana insufficiente!"
    attacker.use_mana(cost)
    for p in party_members:
        p.status.damage_buff_turns = 3
        p.status.damage_buff_amount = 0.33
    return f"{attacker.name} ispira la squadra (+33% danni per 3 turni)."

def rogue_ult(attacker, enemies_list):
    cost = attacker.mana
    if cost <= 0:
        return "Mana insufficiente!"
    attacker.use_mana(cost)
    messages = []
    for e in enemies_list:
        if not e.alive: continue
        dmg = e.max_hp * 0.40
        if attacker.status.damage_buff_turns > 0:
            dmg *= (1 + attacker.status.damage_buff_amount)
        if e.status.marked:
            dmg *= 2
            e.status.marked = False
        dealt = e.take_damage(dmg)
        e.status.stunned = max(e.status.stunned, 2)
        messages.append(f"{e.name} -{dealt} (stun 2)")
    return f"{attacker.name} scaglia 'Urlo del Dominatore': " + "; ".join(messages)

# ---------- BATTLE SYSTEM ------------
def build_turn_list():
    lst = []
    for p in party:
        lst.append(p)
    for e in enemies:
        lst.append(e)
    return lst

full_turn_list = build_turn_list()
turn_index = -1
battle_log = []
move_display = ""
def next_turn():
    global turn_index
    n = len(full_turn_list)
    for _ in range(n):
        turn_index = (turn_index + 1) % n
        current = full_turn_list[turn_index]
        if current.alive:
            if current.status.slow_turns > 0:
                current.status.slow_turns -= 1
                battle_log.insert(0, f"{current.name} è rallentato e salta il turno.")
                continue
            return current
    return None
def get_current():
    if 0 <= turn_index < len(full_turn_list):
        return full_turn_list[turn_index]
    return None

# ---------- UI: rectangles for clicks ----------
BTN_RECTANGLES = []  # tuples (rect, key)
enemy_rects = []      # tuples (rect, enemy)
ally_rects = []       # tuples (rect, ally)

# Game states: "menu", "battle", "target_select"
game_state = "menu"
target_selection_info = None  # dict: ability_key, caster, target_type, max_targets, selected(list)

def draw_bar(surface, x, y, w, h, pct, color_bg=(40,40,40), color_fg=(0,200,0)):
    pygame.draw.rect(surface, color_bg, (x,y,w,h))
    inner_w = int(w * clamp(pct, 0, 1))
    pygame.draw.rect(surface, color_fg, (x,y,inner_w,h))
    pygame.draw.rect(surface, (0,0,0), (x,y,w,h), 2)

def draw_menu():
    WIN.fill((20,20,40))
    title = BIGFONT.render("JRPG Turn-Based Demo", True, (255,255,255))
    WIN.blit(title, (WIDTH//2 - title.get_width()//2, HEIGHT//4))
    start_btn = pygame.Rect(WIDTH//2 - 100, HEIGHT//2 - 40, 200, 50)
    exit_btn = pygame.Rect(WIDTH//2 - 100, HEIGHT//2 + 40, 200, 50)
    pygame.draw.rect(WIN, (80,160,80), start_btn)
    pygame.draw.rect(WIN, (160,80,80), exit_btn)
    WIN.blit(FONT.render("Inizia", True, (255,255,255)), (start_btn.x+70, start_btn.y+15))
    WIN.blit(FONT.render("Esci", True, (255,255,255)), (exit_btn.x+80, exit_btn.y+15))
    pygame.display.flip()
    return start_btn, exit_btn

def draw_battle(highlight_targets=None, selected_targets=None):
    # highlight_targets: set of objects to visually indicate as selectable
    # selected_targets: set of objects currently selected
    WIN.fill((30,30,40))
    title = BIGFONT.render("Demo JRPG Turn-Based", True, (255,255,255))
    WIN.blit(title, (20, 8))

    # Party panel (left)
    x0, y0 = 20, 50
    ally_rects.clear()
    for i, p in enumerate(party):
        px = x0
        py = y0 + i*140
        rect = pygame.Rect(px, py, 220, 120)
        ally_rects.append((rect, p))
        pygame.draw.rect(WIN, p.color if p.alive else (80,80,80), rect)
        WIN.blit(FONT.render(f"{p.name} ({p.role})", True, (0,0,0)), (px+8, py+6))
        draw_bar(WIN, px+8, py+34, 200, 18, p.hp/p.max_hp, (40,40,40), (120,240,120))
        WIN.blit(FONT.render(f"HP: {p.hp}/{p.max_hp}", True, (0,0,0)), (px+8, py+34))
        draw_bar(WIN, px+8, py+60, 200, 14, p.mana/p.max_mana, (40,40,40), (80,160,255))
        WIN.blit(FONT.render(f"MP: {p.mana}/{p.max_mana}", True, (0,0,0)), (px+8, py+60))
        st = []
        if p.status.damage_buff_turns>0: st.append(f"Buff+{int(p.status.damage_buff_amount*100)}%({p.status.damage_buff_turns})")
        if p.status.taunt>0: st.append(f"Taunt({p.status.taunt})")
        if p.status.stunned>0: st.append(f"Stun({p.status.stunned})")
        if not p.alive: st = ["KO"]
        st_text = FONT.render(", ".join(st), True, (0,0,0))
        WIN.blit(st_text, (px+8, py+84))

    # Enemies (right)
    ex, ey = 260, 50
    enemy_rects.clear()
    for i, e in enumerate(enemies):
        px = ex + (i%2)*380
        py = ey + (i//2)*160
        rect = pygame.Rect(px, py, 360, 140)
        enemy_rects.append((rect, e))
        pygame.draw.rect(WIN, e.color if e.alive else (80,80,80), rect)
        WIN.blit(FONT.render(f"{e.name}", True, (0,0,0)), (px+8, py+6))
        draw_bar(WIN, px+8, py+34, 340, 18, e.hp/e.max_hp, (40,40,40), (220,120,80))
        WIN.blit(FONT.render(f"HP: {e.hp}/{e.max_hp}", True, (0,0,0)), (px+8, py+34))
        st = []
        if e.status.stunned>0: st.append(f"Stun({e.status.stunned})")
        if e.status.attack_down_turns>0: st.append("Atk -50%")
        if e.status.slow_turns>0: st.append(f"Slow({e.status.slow_turns})")
        if e.status.marked: st.append("Marchiato")
        st_text = FONT.render(", ".join(st), True, (0,0,0))
        WIN.blit(st_text, (px+8, py+84))

    # bottom UI background
    ui_y = 460
    pygame.draw.rect(WIN, (20,20,30), (0, ui_y, WIDTH, HEIGHT-ui_y))
    # current turn
    current = get_current()
    turn_text = BIGFONT.render(f"Turno attuale: {current.name if current else '---'}", True, (255,255,255))
    WIN.blit(turn_text, (20, ui_y+8))
    # move display
    md = FONT.render(move_display, True, (230,230,230))
    WIN.blit(md, (20, ui_y+48))

    # Buttons for abilities (only if player turn)
    BTN_RECTANGLES.clear()
    if current in party and current.alive:
        bx = 20
        by = ui_y + 90
        bw = 240; bh = 40; gap = 12
        btns = []
        if current.role == "Mago":
            btns = [
                ("Luce Arcana (+44%)", "mage_boost"),
                ("Vento Gelido (Slow)", "mage_slow"),
                ("Cura (55%/80% crit)", "mage_heal"),
                ("Resurrezione (30% HP)", "mage_res")
            ]
        elif current.role == "Guerriero":
            btns = [
                ("Colpo Rapido (35%)", "war_normal"),
                ("Colpo Pesante (75%)", "war_heavy"),
                ("Marchio (next dmg x2)", "war_mark"),
                ("Furia (self +25%)", "war_selfbuff")
            ]
        elif current.role == "Arciere":
            btns = [
                ("Pioggia (AOE 15%)", "arch_aoe"),
                ("Doppia Mira (2 target 30%)", "arch_two"),
                ("Freccia Gravità (-50% attacchi 1t)", "arch_gravity"),
                ("Alba Infernale (80% singolo, mana all-in)", "arch_ult")
            ]
        elif current.role == "Predone":
            btns = [
                ("Provocazione (Draw aggro)", "rog_taunt"),
                ("Stordimento (1 t)", "rog_stun"),
                ("Benedizione (Party +33%)", "rog_partybuff"),
                ("Urlo Dominatore (40% + stun 2 t, mana all-in)", "rog_ult")
            ]
        for i, (label, key) in enumerate(btns):
            r = pygame.Rect(bx + i*(bw+gap), by, bw, bh)
            pygame.draw.rect(WIN, (70,70,90), r)
            txt = FONT.render(label, True, (230,230,230))
            WIN.blit(txt, (r.x+8, r.y+8))
            cost = COST.get(key)
            cost_text = f"MP: {'ALL' if cost is None else cost}"
            mc = FONT.render(cost_text, True, (200,200,200))
            WIN.blit(mc, (r.x+8, r.y+24))
            BTN_RECTANGLES.append((r, key))

    # battle log (top 6)
    lx = 20; ly = ui_y + 150
    for i, line in enumerate(battle_log[:6]):
        s = FONT.render(line, True, (240,240,240))
        WIN.blit(s, (lx, ly + i*20))

    # turn order display
    to_x = 820; to_y = 60
    WIN.blit(FONT.render("Ordine Turni:", True, (255,255,255)), (to_x, to_y))
    for i, actor in enumerate(full_turn_list):
        col = (180,180,180)
        status_str = ""
        if isinstance(actor, Enemy):
            col = actor.color if actor.alive else (60,60,60)
            status_str = "(N)"
        else:
            col = actor.color if actor.alive else (60,60,60)
            status_str = "(P)"
        rect = pygame.Rect(to_x, to_y + 30 + i*28, 240, 24)
        pygame.draw.rect(WIN, col, rect)
        txt = FONT.render(f"{actor.name} {status_str}", True, (0,0,0))
        WIN.blit(txt, (rect.x + 6, rect.y + 3))

    # highlight selectable targets if provided
    if highlight_targets:
        for (rect, obj) in enemy_rects + ally_rects:
            if obj in highlight_targets:
                pygame.draw.rect(WIN, (255,220,60), rect, 4)
    # highlight already selected
    if selected_targets:
        for (rect, obj) in enemy_rects + ally_rects:
            if obj in selected_targets:
                pygame.draw.rect(WIN, (60,220,255), rect, 4)

    pygame.display.flip()

# ---------- TARGET REQ mapping ----------
# None => immediate use / area / self; otherwise provide target_type and max_targets
ABILITY_TARGET_REQ = {
    "mage_boost": None,
    "mage_slow": None,
    "mage_heal": {"target_type":"ally","max_targets":1},
    "mage_res": {"target_type":"ally_dead","max_targets":1},
    "war_normal": {"target_type":"enemy","max_targets":1},
    "war_heavy": {"target_type":"enemy","max_targets":1},
    "war_mark": {"target_type":"enemy","max_targets":1},
    "war_selfbuff": None,
    "arch_aoe": None,
    "arch_two": {"target_type":"enemy","max_targets":2},
    "arch_gravity": None,
    "arch_ult": {"target_type":"enemy","max_targets":1},
    "rog_taunt": None,
    "rog_stun": {"target_type":"enemy","max_targets":1},
    "rog_partybuff": None,
    "rog_ult": None
}

# ---------- HELPERS per scelta bersaglio ----------
def get_rect_under_pos(pos):
    for rect, e in enemy_rects:
        if rect.collidepoint(pos):
            return e
    for rect, a in ally_rects:
        if rect.collidepoint(pos):
            return a
    return None

def allowed_target_by_type(obj, ttype):
    if ttype == "enemy":
        return isinstance(obj, Enemy) and obj.alive
    if ttype == "enemy_any":
        return isinstance(obj, Enemy)
    if ttype == "ally":
        return (not isinstance(obj, Enemy)) and obj.alive
    if ttype == "ally_dead":
        return (not isinstance(obj, Enemy)) and (not obj.alive)
    return False

# ---------- MAIN LOOP ----------
clock = pygame.time.Clock()
FPS = 30
running = True
start_btn = None; exit_btn = None
turn_index = -1
current_actor = None

while running:
    clock.tick(FPS)
    if game_state == "menu":
        start_btn, exit_btn = draw_menu()
        for event in pygame.event.get():
            if event.type == QUIT:
                running = False
            elif event.type == MOUSEBUTTONDOWN and event.button == 1:
                if start_btn.collidepoint(event.pos):
                    # reset states and start battle
                    full_turn_list = build_turn_list()
                    battle_log.clear()
                    turn_index = -1
                    current_actor = next_turn()
                    move_display = ""
                    game_state = "battle"
                elif exit_btn.collidepoint(event.pos):
                    running = False

    elif game_state == "battle":
        # draw normal battle UI
        draw_battle()
        for event in pygame.event.get():
            if event.type == QUIT:
                running = False
            elif event.type == KEYDOWN:
                if event.key == K_ESCAPE:
                    # no-op in battle
                    pass
            elif event.type == MOUSEBUTTONDOWN and event.button == 1:
                mx,my = event.pos
                current = get_current()
                # if it's a player turn, check buttons
                if current in party and current.alive:
                    clicked_btn = None
                    for rect, key in BTN_RECTANGLES:
                        if rect.collidepoint((mx,my)):
                            clicked_btn = key; break
                    if clicked_btn:
                        # Determine if this ability needs target(s)
                        req = ABILITY_TARGET_REQ.get(clicked_btn)
                        if req is None:
                            # immediate / AoE / self - execute now
                            msg = "Azioni..."
                            if clicked_btn == "mage_boost":
                                msg = mage_boost(current, party)
                            elif clicked_btn == "mage_slow":
                                msg = mage_slow(current, enemies)
                            elif clicked_btn == "war_selfbuff":
                                msg = warrior_selfbuff(current)
                            elif clicked_btn == "arch_aoe":
                                msg = archer_aoe(current, enemies)
                            elif clicked_btn == "arch_gravity":
                                msg = archer_gravity(current, enemies)
                            elif clicked_btn == "rog_taunt":
                                msg = rogue_taunt(current)
                            elif clicked_btn == "rog_partybuff":
                                msg = rogue_partybuff(current, party)
                            elif clicked_btn == "rog_ult":
                                msg = rogue_ult(current, enemies)
                            else:
                                msg = "Mossa non implementata."
                            battle_log.insert(0, msg)
                            # if mana insuff, allow retry (do not advance turn)
                            if msg == "Mana insufficiente!":
                                move_display = msg
                            else:
                                # tick statuses and advance
                                for actor in full_turn_list: actor.tick()
                                current_actor = next_turn()
                        else:
                            # need manual selection
                            target_selection_info = {
                                "ability_key": clicked_btn,
                                "caster": current,
                                "target_type": req["target_type"],
                                "max_targets": req["max_targets"],
                                "selected": []
                            }
                            move_display = f"{current.name} -> Seleziona bersaglio ({target_selection_info['max_targets']})"
                            game_state = "target_select"
                # else: clicking while not player's turn does nothing

        # after event processing, if it's enemy's turn, let AI act automatically
        current = get_current()
        if current and isinstance(current, Enemy) and current.alive:
            # small delay for readability could be added via time but we'll just run
            if current.status.stunned > 0:
                battle_log.insert(0, f"{current.name} è stordito e salta il turno.")
                current.status.stunned -= 1
                for actor in full_turn_list: actor.tick()
                current_actor = next_turn()
            else:
                # choose target respecting taunt
                taunted = [p for p in party if p.status.taunt > 0 and p.alive]
                if taunted:
                    target = taunted[0]
                else:
                    target = current.choose_target(party)
                if target is None:
                    current_actor = next_turn()
                else:
                    base = target.max_hp * current.attack_pct
                    if current.status.attack_down_turns > 0:
                        base = target.max_hp * (current.attack_pct * 0.5)
                    dealt = target.take_damage(base)
                    battle_log.insert(0, f"{current.name} attacca {target.name} per {dealt} HP.")
                    for actor in full_turn_list: actor.tick()
                    current_actor = next_turn()

        # win/lose checks
        if not any(e.alive for e in enemies):
            battle_log.insert(0, "Hai vinto! Tutti i nemici sconfitti.")
            draw_battle()
            pygame.time.wait(1500)
            game_state = "menu"
        if not any(p.alive for p in party):
            battle_log.insert(0, "Sconfitta... Tutta la squadra è caduta.")
            draw_battle()
            pygame.time.wait(1500)
            game_state = "menu"

    elif game_state == "target_select":
        # Determine highlight set
        info = target_selection_info
        if info is None:
            game_state = "battle"; continue
        allow_type = info["target_type"]
        # build highlight set
        highlight = set()
        if allow_type == "enemy":
            for _,e in enemy_rects:
                if e.alive: highlight.add(e)
        elif allow_type == "enemy_dead":
            for _,e in enemy_rects:
                if not e.alive: highlight.add(e)
        elif allow_type == "ally":
            for _,a in ally_rects:
                if a.alive: highlight.add(a)
        elif allow_type == "ally_dead":
            for _,a in ally_rects:
                if not a.alive: highlight.add(a)
        else:
            # fallback: enemy
            for _,e in enemy_rects:
                if e.alive: highlight.add(e)

        selected_set = set(info["selected"])
        draw_battle(highlight_targets=highlight, selected_targets=selected_set)

        for event in pygame.event.get():
            if event.type == QUIT:
                running = False
            elif event.type == KEYDOWN and event.key == K_ESCAPE:
                # cancel selection
                target_selection_info = None
                move_display = ""
                game_state = "battle"
            elif event.type == MOUSEBUTTONDOWN:
                if event.button == 3:
                    # right click cancels
                    target_selection_info = None
                    move_display = ""
                    game_state = "battle"
                elif event.button == 1:
                    mx,my = event.pos
                    obj = get_rect_under_pos((mx,my))
                    if obj is None:
                        continue
                    # check if allowed
                    if not allowed_target_by_type(obj, allow_type):
                        continue
                    # add selection
                    if obj in info["selected"]:
                        # unselect if already selected
                        info["selected"].remove(obj)
                    else:
                        info["selected"].append(obj)
                    # update move display
                    move_display = f"{info['caster'].name} -> Selezionati: {[o.name for o in info['selected']]}"
                    # if enough targets selected, execute
                    if len(info["selected"]) >= info["max_targets"]:
                        # execute ability based on key
                        key = info["ability_key"]
                        caster = info["caster"]
                        selected = info["selected"]
                        msg = "Azione..."
                        if key == "mage_heal":
                            tgt = selected[0]
                            msg = mage_heal(caster, tgt)
                        elif key == "mage_res":
                            tgt = selected[0]
                            msg = mage_resurrect(caster, tgt)
                        elif key == "war_normal":
                            tgt = selected[0]
                            msg = warrior_normal(caster, tgt)
                        elif key == "war_heavy":
                            tgt = selected[0]
                            msg = warrior_heavy(caster, tgt)
                        elif key == "war_mark":
                            tgt = selected[0]
                            msg = warrior_mark(caster, tgt)
                        elif key == "arch_two":
                            # pass selected list
                            msg = archer_two(caster, selected)
                        elif key == "arch_ult":
                            tgt = selected[0]
                            msg = archer_ult(caster, tgt)
                        elif key == "rog_stun":
                            tgt = selected[0]
                            msg = rogue_stun(caster, tgt)
                        else:
                            msg = "Mossa non implementata."
                        battle_log.insert(0, msg)
                        # if mana insuff, don't advance turn, allow retry
                        if msg == "Mana insufficiente!":
                            move_display = msg
                            # remain in battle state so player can choose again
                            target_selection_info = None
                            game_state = "battle"
                        else:
                            # tick statuses and advance turn
                            for actor in full_turn_list: actor.tick()
                            current_actor = next_turn()
                            target_selection_info = None
                            move_display = ""
                            game_state = "battle"

        # if somehow all possible targets vanished, cancel
        if info:
            possible = [o for o in highlight if allowed_target_by_type(o, info["target_type"])]
            if not possible:
                target_selection_info = None
                move_display = ""
                game_state = "battle"

# end main loop
pygame.quit()
sys.exit()
