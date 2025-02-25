import random

lista = []
for i in range(20):
    lista.append(random.randint(1,100))

print(lista)

somma = 0
for i in lista:
    somma += i
media = somma / 20

print('La media aritmetica è', media)
