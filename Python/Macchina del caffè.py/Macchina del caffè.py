import main
import os

macchinetta = True

Quarter = 0.25
Dime = 0.10
Nickel = 0.05
Penny = 0.01
importo_totale = 0.0


def pagamento(tipo_caffe):
    global importo_totale
    print(f"Quanti quarter vuoi inserire?")
    quarter = int(input())
    print(f"Quanti dime vuoi inserire?")
    dime = int(input())
    print(f"Quanti nichel vuoi inserire?")
    nickel = int(input())
    print(f"Quanti penny vuoi inserire?")
    penny = int(input())
    totale = (quarter * Quarter) + (dime * Dime) + (nickel * Nickel) + (penny * Penny)
    if tipo_caffe == "espresso":
        if totale >= main.MENU["espresso"]["cost"]:
            resto = totale - main.MENU["espresso"]["cost"]
            importo_totale += main.MENU["espresso"]["cost"]
            print(f"Il resto è: {resto:.2f}€")
            return 1
        else:
            print("Spiacente, non hai inserito abbastanza denaro. Denaro rimborsato.")
            return 0
    elif tipo_caffe == "latte":
        if totale >= main.MENU["latte"]["cost"]:
            resto = totale - main.MENU["latte"]["cost"]
            importo_totale += main.MENU["latte"]["cost"]
            print(f"Il resto è: {resto:.2f}€")
            return 1
        else:
            print("Spiacente, non hai inserito abbastanza denaro. Denaro rimborsato.")
            return 0
    elif tipo_caffe == "cappuccino":
        if totale >= main.MENU["cappuccino"]["cost"]:
            resto = totale - main.MENU["cappuccino"]["cost"]
            importo_totale += main.MENU["cappuccino"]["cost"]
            print(f"Il resto è: {resto:.2f}€")
            return 1
        else:
            print("Spiacente, non hai inserito abbastanza denaro. Denaro rimborsato.")
            return 0


def prepara_caffe(tipo_caffe):
    if tipo_caffe == "espresso":
        if main.resources["water"] >= main.MENU["espresso"]["ingredients"]["water"] and main.resources["coffee"] >= main.MENU["espresso"]["ingredients"]["coffee"]:
            main.resources["water"] -= main.MENU["espresso"]["ingredients"]["water"]
            main.resources["coffee"] -= main.MENU["espresso"]["ingredients"]["coffee"]
        else:
            print("Risorse insufficienti per preparare un espresso.")
    elif tipo_caffe == "latte":
        if main.resources["water"] >= main.MENU["latte"]["ingredients"]["water"] and main.resources["milk"] >= main.MENU["latte"]["ingredients"]["milk"] and main.resources["coffee"] >= main.MENU["latte"]["ingredients"]["coffee"]:
            main.resources["water"] -= main.MENU["latte"]["ingredients"]["water"]
            main.resources["milk"] -= main.MENU["latte"]["ingredients"]["milk"]
            main.resources["coffee"] -= main.MENU["latte"]["ingredients"]["coffee"]
        else:
            print("Risorse insufficienti per preparare un latte.")
    elif tipo_caffe == "cappuccino":
        if main.resources["water"] >= main.MENU["cappuccino"]["ingredients"]["water"] and main.resources["milk"] >= main.MENU["cappuccino"]["ingredients"]["milk"] and main.resources["coffee"] >= main.MENU["cappuccino"]["ingredients"]["coffee"]:
            main.resources["water"] -= main.MENU["cappuccino"]["ingredients"]["water"]
            main.resources["milk"] -= main.MENU["cappuccino"]["ingredients"]["milk"]
            main.resources["coffee"] -= main.MENU["cappuccino"]["ingredients"]["coffee"]
        else:
            print("Risorse insufficienti per preparare un cappuccino.")


while macchinetta:
    print("\nBenvenuto nella macchina del caffè!\n")
    richiesta = input("Cosa desideri? (espresso/latte/cappuccino):").lower()

    if richiesta == "report":
        print("Risorse disponibili:")
        print(f"Acqua: {main.resources['water']}ml")
        print(f"Latte: {main.resources['milk']}ml")
        print(f"Caffè: {main.resources['coffee']}g")
        print(f"Importo totale accumulato: {importo_totale:.2f}€")
    elif richiesta == "off":
        print("Macchina spenta.")
        macchinetta = False
    elif richiesta in main.MENU:
        print(f"Un {richiesta} costa {main.MENU[richiesta]['cost']:.2f}€")
        if pagamento(richiesta) == 1:
            prepara_caffe(richiesta)
            print(f"Ecco il tuo {richiesta}. Buona degustazione!")
        else:
            print(f"Non è stato possibile preparare il tuo {richiesta}.")
    else:
        print("Scelta non valida. Riprova.")


