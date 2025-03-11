import random

word_list = ["arancia", "babbuino", "cammello"]

parola_scelta = random.choice(word_list)
print(parola_scelta)

segnaposto = ""
lungh_parola = len(parola_scelta)
for posizione in range(lungh_parola):
    segnaposto += "_"
print(segnaposto)

tentativo = ""
display = segnaposto
lettere_indovinate = set()

while "_" in display:
    while not tentativo.isalpha() or len(tentativo) != 1 or tentativo in lettere_indovinate:
        tentativo = input("Indovina la lettera: ").lower()

    lettere_indovinate.add(tentativo)

    new_display = ""
    for index in range(len(parola_scelta)):
        lettera = parola_scelta[index]
        if lettera == tentativo:
            new_display += lettera
        else:
            new_display += display[index]

    display = new_display
    print(display)

print("Hai vinto!")


