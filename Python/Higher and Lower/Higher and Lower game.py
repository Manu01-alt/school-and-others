import art
import game_data
import random
import os

score = 0
game_over = False

while game_over == False:
    print(art.logo)

    primo = random.choice(game_data.data)
    secondo = random.choice(game_data.data)

    while primo == secondo:
        secondo = random.choice(game_data.data)

    print(primo["name"] + ", " + primo["description"] + ", " + primo["country"])
    print(art.vs)
    print(secondo["name"] + ", " + secondo["description"] + ", " + secondo["country"])

    print("\nChi ha più follower? A o B?")

    risposta = input("Risposta: ").upper()

    if risposta == "A":
        if primo["follower_count"] > secondo["follower_count"]:
            os.system("cls")
            print("Esatto!")
            score += 1
        else:
            print("Sbagliato, hai perso!")
            print(f"Final score: {score}")
            game_over = True


    elif risposta == "B":
        if secondo["follower_count"] > primo["follower_count"]:
            os.system("cls")
            print("Esatto!")
            score += 1
        else:
            print("Sbagliato, hai perso!")
            print(f"Final score: {score}")
            game_over = True


