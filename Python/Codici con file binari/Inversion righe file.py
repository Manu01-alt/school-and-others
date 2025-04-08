file = open("primo.txt", "r") 

riga = file.readlines()
riga = riga[::-1] 
file.close()

file = open("secondo.txt", "w") 
for i in riga:
    file.write(i)

file.close()