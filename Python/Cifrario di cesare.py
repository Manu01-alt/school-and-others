frase = input("Inserire una frase: ")
numero = int(input("Inserire un'intero: "))

senfr = ""

for i in frase:
    if i == " ":
        senfr += " "
    else:
        if i.isupper():
            rot = chr((ord(i) - ord('A') + numero) % 26 + ord('A'))
        elif i.islower():
            rot = chr((ord(i) - ord('a') + numero) % 26 + ord('a'))
        else:
            rot = i 
        
        senfr += rot
print(senfr)
    



