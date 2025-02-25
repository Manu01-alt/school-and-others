#Password Generator Project
password = ""

import random
letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
symbols = ['!', '#', '$', '%', '&', '(', ')', '*', '+']

print("Benvenuto nel generatore di password!")
nr_letters= int(input("Quante lettere vuoi nella tua password? ")) 
nr_symbols = int(input("Quanti simboli vuoi? "))
nr_numbers = int(input("Quanti numeri vuoi? "))

#Livello facile - Ordine non randomizzato:
#e.g. 4 letter, 2 symbol, 2 number = JduE&!91


#Funziona, ma è uno spreco di memoria, tu vai a creare nuove stringhe ogni volta che fai +=, meglio usare una lista
# Aggiungi lettere casuali alla password
# for i in range(0, nr_letters): 
#     password += random.choice(letters)
# Aggiungi simboli casuali alla password
# for i in range(0, nr_symbols):
#     password += random.choice(symbols)
# Aggiungi numeri casuali alla password
# for i in range(0, nr_numbers):
#     password += random.choice(numbers) 
    

#utilizzando il join, possiamo creare una lista con tutte le lettere, i numeri e i simboli e poi unirli in una stringa
password_list = []
for i in range(0, nr_letters):
    password_list.append(random.choice(letters))
for i in range(0, nr_symbols):
    password_list.append(random.choice(symbols))
for i in range(0, nr_numbers):
    password_list.append(random.choice(numbers))
password = "".join(password_list)

print("La password generata e' ",password)
#Livello medio - Ordine dei caratteri randomizzato:
#e.g. 4 letter, 2 symbol, 2 number = g^2jk8&P

# password_list = list(password) 
# random.shuffle(password_list) 
# 
# password = ""   
# 
# for i in password_list:
#     password += i
# 
# print("La password con ordine randomizzato e' ",password)

#Un metodo più rapido per far diventare una lisa una stringa è usare il metodo join
#password = "".join(password_list)

password_list = list(password)
random.shuffle(password_list)
password = "".join(password_list)

print("La password con ordine randomizzato e' ",password)

