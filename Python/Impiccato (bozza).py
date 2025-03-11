import random

Turno = True
ps = 9

word_list = ["arancia", "babbuino", "cammello"]

parola_scelta = random.choice(word_list)
print(parola_scelta)

segnaposto = ["_"] * len(parola_scelta)
print(" ".join(segnaposto))

tentativo = ""


while Turno == True:

    while not tentativo.isalpha() or len(tentativo) != 1:
        tentativo = input("Inserisci una lettera: ").lower()

    for index in range(len(parola_scelta)):
        lettera = parola_scelta[index]
    
        if lettera == tentativo:
            segnaposto[index] = lettera
        else:
            ps -= 1
            print("Hai ancora", ps, "tentativi")

    print(" ".join(segnaposto))
    
    if ps == 0:
        print("Hai perso!")
        Turno = False 


