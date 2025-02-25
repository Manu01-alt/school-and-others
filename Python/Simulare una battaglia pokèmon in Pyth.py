import random

# Scelta dell'allenatore tra Rosso o Blu
allenatore = input("Scegli l'allenatore tra Rosso e Blu: ")
if allenatore == "Rosso":
    print("Hai scelto Rosso")
elif allenatore == "Blu":
    print("Hai scelto Blu")
else:
    print("Allenatore non valido")
    exit()

# Formazione delle squadre
squadre = {
    "Rosso": ["Charizard", "Pikachu", "Dragonite"],
    "Blu": ["Blastoise", "Jolteon", "Ekans"]
}

# Scelta del Pokémon iniziale
def scegli_pokemon():
    while True:
        pokemon = input(f"Scegli il Pokémon da far combattere tra {', '.join(squadre[allenatore])}: ")
        if pokemon in squadre[allenatore]:
            print(f"Hai scelto {pokemon}")
            return pokemon
        else:
            print("Pokémon non valido")

Pokemon = scegli_pokemon()

# Mosse e danni
mosse = {
    "Charizard": ["Lanciafiamme", "Dragoartigli"],
    "Pikachu": ["Fulmine", "Codacciaio"],
    "Dragonite": ["Dragobolide", "Dragoartigli"],
    "Blastoise": ["Idropompa", "Idrocannone"],
    "Jolteon": ["Tuono", "Azione"],
    "Ekans": ["Fangoblu", "Pugnoscarica"]
}

danni = {
    "Lanciafiamme": 90,
    "Dragoartigli": 80,
    "Fulmine": 75,
    "Codacciaio": 50,
    "Dragobolide": 90,
    "Idropompa": 90,
    "Idrocannone": 75,
    "Tuono": 85,
    "Azione": 20,
    "Fangoblu": 75,
    "Pugnoscarica": 50
}

vita_pokemon = {
    "Charizard": 200,
    "Pikachu": 150,
    "Dragonite": 200,
    "Blastoise": 200,
    "Jolteon": 150,
    "Ekans": 150
}

# Funzione per scegliere la mossa o cambiare Pokémon
def scegli_azione(pokemon):
    while True:
        azione = input("Vuoi attaccare o cambiare Pokémon? (attacco/cambia): ")
        if azione == "attacco":
            while True:
                mossa = input(f"Scegli la mossa tra {', '.join(mosse[pokemon])}: ")
                if mossa in mosse[pokemon]:
                    print(f"{pokemon} usa {mossa}")
                    return "attacco", mossa
                else:
                    print("Mossa non valida")
        elif azione == "cambia":
            if len(squadre[allenatore]) > 1:
                while True:
                    nuovo_pokemon = input(f"Scegli il Pokémon da far combattere tra {', '.join([p for p in squadre[allenatore] if p != pokemon])}: ")
                    if nuovo_pokemon in squadre[allenatore] and nuovo_pokemon != pokemon:
                        print(f"Hai cambiato Pokémon! Ora combatti con {nuovo_pokemon}")
                        return "cambia", nuovo_pokemon
                    else:
                        print("Pokémon non valido")
            else:
                print("Non puoi cambiare Pokémon, ne hai solo uno disponibile!")
        else:
            print("Scelta non valida")

# Funzione per aggiornare la vita di un Pokémon
def aggiorna_vita(pokemon, danno):
    vita_pokemon[pokemon] -= danno
    print(f"Vita di {pokemon} dopo l'attacco: {vita_pokemon[pokemon]}")
    if vita_pokemon[pokemon] <= 0:
        print(f"{pokemon} è esausto!")
        return False
    return True

# Funzione per IA avversario
def ia_avversario():
    pokemon_avversario = random.choice(squadre["Blu"])
    mossa_avversario = random.choice(mosse[pokemon_avversario])
    print(f"L'avversario sceglie {pokemon_avversario} e usa {mossa_avversario}")
    return pokemon_avversario, mossa_avversario

# Inizio della battaglia
while True:
    azione, scelta = scegli_azione(Pokemon)
    
    if azione == "cambia":
        Pokemon = scelta
        continue
    
    mossa_player = scelta
    danno_player = danni[mossa_player]
    
    pokemon_avversario, mossa_avversario = ia_avversario()
    danno_avversario = danni[mossa_avversario]
    
    if not aggiorna_vita(pokemon_avversario, danno_player):
        squadre["Blu"].remove(pokemon_avversario)
        if len(squadre["Blu"]) == 0:
            print("Tutti i Pokémon di Blu sono esausti! Rosso vince!")
            break

    if not aggiorna_vita(Pokemon, danno_avversario):
        squadre[allenatore].remove(Pokemon)
        if len(squadre[allenatore]) == 0:
            print(f"Tutti i Pokémon di {allenatore} sono esausti! Blu vince!")
            break
        else:
            Pokemon = scegli_pokemon()
