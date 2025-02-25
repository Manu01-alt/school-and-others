Stringa = input("Inserire una frase: ")

Stringa_filtrata=""

for i in Stringa: 
    if i.isalpha():
        Stringa_filtrata += i

if Stringa_filtrata == Stringa_filtrata[::-1]:
    print("La frase è palindroma")
else:
    print("La frase non è palindroma")




