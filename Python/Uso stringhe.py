#il valore in più è il passo, cioè di quanto in quanto si deve incrementare il valore di partenza
#questo significa che prendo uno ogni due caratteri
#quindi il risultato è "aaa"

stringa = "banana"

print(stringa[1:6:2])

# "b a n a n a" 
#  0 1 2 3 4 5
#parto da 1, salto il 2 e prendo il 3, salto il 4 e prendo il 5

print(stringa[::2])

#senza specificare partenza e arrivo, lavoro su tutta la stringa
#quindi il risultato è "bnn"

stringa = "banana"

print(stringa[::-1])
#andando indietro di 1 e lavorando su tutta la stringa, parto dall'ultimo carattere e vado indietro
#quindi il risultato è "ananab"

stringa = "itopin onaveva non ipot i"

print(stringa[::-1])

#questa è una stringa palindroma, cioè che si legge allo stesso modo da sinistra a destra e da destra a sinistra

stringa = " Hello, World! "

print(stringa.upper()) #trasforma tutti i caratteri in maiuscolo

print(stringa.lower()) #trasforma tutti i caratteri in minuscolo

print(stringa.strip()) #rimuove gli spazi bianchi all'inizio e alla fine della stringa

#Questi sono strumenti utili per la pulizia dei dati

stringa = "Hello, World!"

print(stringa.replace("H", "J")) #sostituisce un carattere con un altro
#Ricorda che è case sensitive, quindi se non trova la H maiuscola non la sostituisce

stringa = "Hello, World!"

print(stringa.split(",")) #divide la stringa in sottostringhe quando trova una virgola
#La parola "Hello" è nella prima sottostringa e la parola "World!" è nella seconda sottostringa, queste sottostringhe sono liste che possono essere manipolate
#Puoi usare un separatore soltanto alla volta, ma puoi usare più separatori in una volta sola come (", ") ovvero virgola e spazio

#Questi sono strumenti utili per la manipolazione dei dati

if "Hello" in stringa:
    print("Si")
else:
    print("No")

#questo è un esempio di controllo di presenza di una sottostringa in una stringa

stringa = "Hello, World!"

print(len(stringa)) #restituisce la lunghezza della stringa

#questo è un esempio di controllo della lunghezza di una stringa

#RICORDA: La stringa è un tipo di dato immutabile, cioè non può essere modificato una volta creato, quello che
#facciamo quando modifichiamo una stringa è creare una nuova stringa

#parliamo di placeholder

price = 49
txt = f"The price is {price} dollars"
#il placeholder è {price} e il valore è 49 che è una variabile, la f sta per format e serve per inserire il valore della variabile nella stringa
print(txt)

#i caratteri di escape sono caratteri speciali che vengono usati per formattare una stringa
#esempi di caratteri di escape sono \n che serve per andare a capo e \t che serve per fare un tab
#esempio di caratteri di escape

txt = "We are the so-called \"Vikings\" from the north."
#il carattere di escape è \ che precede il carattere che vogliamo inserire nella stringa
print(txt)
#possiamo usare ad esempio come in c lo \n per andare a capo
txt = "Hello\nWorld!"
print(txt)

#ESEMPIO: 
#splitto una frase e uso il risultato per una lista
#************************************************************
import random 
frase = "Ciao, come stai?"

lista = frase.split(" ")
lista2= random.shuffle(lista)
print(lista)
#************************************************************

#ESEMPIO:
#************************************************************
age = 36
txt = "My name is John, and I am " + str(age) 
#il metodo str() converte il valore in stringa
print(txt)
#************************************************************

#Provo ad usare il join

lista = ["Ciao", "come", "stai?"]

frase = " ".join(lista) #join vuol dire unisci, quindi unisco la lista con uno spazio tra le parole
print(frase)
#se metto un carattere separatore, ad esempio "," posso separare le parole con la virgola

frase = ", ".join(lista)    
print(frase)
