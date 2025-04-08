# file = open("saluto.txt", "w") #apriamo il file in modalità lettura 

#MODALITA' DI APERTURA
#r = read (lettura) - Presuppone che il file esista
#w = write (scrittura) (overwrite) - se il non esiste lo crea
#a = aggiunta - aggiunge al file, non sovrascrivendo
#b = binary (binario)
#r+ = read and write (lettura e scrittura)

'''
file.write("Ciao 3C Inf!") 
print("HO SCRITTO NEL FILE")
file.close() 
'''

#read() - legge tutto il file
#readline() - legge una riga alla volta
#readlines() - legge tutto il file ein una lista

# file = open("saluto.txt", "r") #apriamo il file in modalità lettura

# contenuto = file.read()

# print(contenuto)

# file.close()

#creare un file chiamato poesia.txt che abbia 3 righe a nostrp piacimento
#fare un programma che legga solo la seconda riga


file = open("poesia.txt", "r")

riga = file.readlines()
riga = riga[1] #prendo la seconda riga

print(riga)
file.close()


