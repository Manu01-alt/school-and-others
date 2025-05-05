numero1 = int(input("Inserisci un numero: "))
numero2 = int(input("Inserisci un secondo numero: "))
operazione = input("Inserisci l'operazione da fare: ")

if operazione == "+":
    risultato = numero1 + numero2
elif operazione == "-":
    risultato = numero1 - numero2
elif operazione == ":":
    risultato = numero1 // numero2
elif operazione == "*":
    risultato = numero1 * numero2

print(risultato)

