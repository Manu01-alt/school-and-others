import random
import os

cards = [11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10]
utente = []
computer = []
punteggio_utente = 0
punteggio_computer = 0
game = True
status = True

while game:
    
    os.system('cls')
    print("Benvenuto al gioco del Black Jack!")
    
    utente.clear()
    computer.clear()
    punteggio_utente = 0
    punteggio_computer = 0
    status = True
    
    for i in range(2):
        utente.append(random.choice(cards))
        computer.append(random.choice(cards))

    
    for i in utente:
        if i == 11 and punteggio_utente + i > 21:
            punteggio_utente += 1
        else:
            punteggio_utente += i
    if punteggio_utente == 21 and punteggio_computer != 21:
        print("Hai un blackjack!")
        print("Hai vinto!")
        status = False

  
    for i in computer:
        if i == 11 and punteggio_computer + i > 21:
            punteggio_computer += 1
        else:   
            punteggio_computer += i
    if punteggio_computer == 21:
        print("Il computer ha un blackjack!")
        print("Hai perso!")
        status = False

    if status == True:
        print(f"Le tue carte sono {utente} e il tuo punteggio è {punteggio_utente}")
        print(f"La prima carta del computer è {computer[0]}")

        richiesta = input("Vuoi pescare un'altra carta? (s/n): ")


        while (richiesta == "s" or richiesta == "S") and status == True:
            utente.append(random.choice(cards))
            if utente[-1] == 11 and punteggio_utente + utente[-1] > 21:
                punteggio_utente += 1
            else:
                punteggio_utente += utente[-1]
            print(f"Le tue carte sono {utente} e il tuo punteggio è {punteggio_utente}")
            
            if punteggio_utente == 21:
                print("Hai raggiunto 21!")
                status = False
            
            if punteggio_utente > 21:
                print("Hai superato 21, hai perso!")
                status = False

            if status == True:
                richiesta = input("Vuoi pescare un'altra carta? (s/n): ")

    
        if punteggio_utente <= 21 and status == True:
            while punteggio_computer <= 16:
                computer.append(random.choice(cards))
                if computer[-1] == 11 and punteggio_computer + computer[-1] > 21:
                    punteggio_computer += 1
                else:
                    punteggio_computer += computer[-1]

            print(f"Le carte del computer sono {computer} e il suo punteggio è {punteggio_computer}")

        
        if punteggio_computer > 21:
            print("Il computer ha superato 21, hai vinto!")
        elif punteggio_utente > punteggio_computer and punteggio_utente <= 21:
            print("Hai vinto!")
        elif punteggio_utente < punteggio_computer or punteggio_computer == 21:
            print("Hai perso!")
        elif punteggio_utente == punteggio_computer:
            print("Pareggio!")

    richiesta = input("Vuoi giocare di nuovo? (s/n): ")
    if richiesta == "n" or richiesta == "N":
        game = False
        os.system('cls')
        print("Grazie per aver giocato!")
    else:
        game = True
