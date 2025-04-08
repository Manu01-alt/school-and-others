

with open("nomi.txt", "a") as file:
    utente = input("Inserisci nome: ")
    file.write(utente + "\n")
    print("Scrtittura nel file avvenuta con successo")