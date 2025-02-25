import random

continua = 0

while continua == 1: 

    domanda = int(input("Testa o Croce? (Testa=0 Croce=1): "))

    moneta = random.randint(0, 1) 

    if moneta == 0:
        print("è uscita Testa")
    else:
        print("è uscita Croce")

    if moneta == domanda:
        print("Hai Vinto!")
    else:
        print("Hai Perso!")

    continua = int(input("Vuoi continuare? (Si=1 No=0): "))

