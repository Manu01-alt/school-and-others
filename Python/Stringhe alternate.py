Stringa1 = input("inserisci la prima stringa: ")
Stringa2 = input ("Inserisci la seconda stringa: ")
Stringa_Completa = ""
counter,j,i = 0,0,0

while counter <= (len(Stringa1) + len(Stringa2)):
    if counter % 2 == 0:
        if i < len(Stringa2):  
            Stringa_Completa += Stringa2[i]
            i += 1
    else:
        if j < len(Stringa1):  
            Stringa_Completa += Stringa1[j]
            j += 1
    counter += 1 


print("La stringa alternata e': ",Stringa_Completa)


