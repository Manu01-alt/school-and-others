# Questo programma stampa i numeri da 1 a n, dove n è un numero inserito dall'utente
numero = int (input("Inserisci un numero: "))
incremento = 1

contatore = 0

if numero > 0:
    while contatore < numero:
        print(incremento)
        incremento = incremento  + 1
        contatore = contatore + 1
else:
    print("Il numero è negativo")
