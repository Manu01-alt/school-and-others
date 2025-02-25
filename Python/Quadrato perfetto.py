numero = int(input("Inserisci un numero: "))
i = 1
quadrato_perfetto = False

while numero < 0:
    print("Il numero è minore di 0, non può essere un quadrato perfetto")
    numero = int(input("Inserisci un numero: "))

while i < numero and quadrato_perfetto == False:
    if i * i == numero:
        print("Il numero è un quadrato perfetto")
        quadrato_perfetto = True
    else:
        i += 1

if quadrato_perfetto == False:
    print("Il numero non è un quadrato perfetto")