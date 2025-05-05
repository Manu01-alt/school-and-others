#programma che fa muovere di 30 pixel la tartaruga in una direzione casuale
from turtle import Turtle, Screen
import turtle as t
import random

def random_color():
    r = random.randint(0, 255)
    g = random.randint(0, 255)
    b = random.randint(0, 255)
    return (r, g, b)

t.colormode(255)
direzioni = [0, 90, 180, 270]
window = Screen()
Zoro = Turtle()
Zoro.shape("turtle") 
Zoro.color("Green")
Zoro.pensize(5)
Zoro.speed('fastest')

for n in range(2000):
    Zoro.pencolor(random_color())
    Zoro.forward(30)
    Zoro.setheading(random.choice(direzioni)) 

exit = window.exitonclick()

