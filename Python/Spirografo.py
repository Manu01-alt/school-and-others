import random
from turtle import Turtle, Screen
import turtle as t

window = Screen()

def random_color():
    r = random.randint(0, 255)
    g = random.randint(0, 255)
    b = random.randint(0, 255)
    return (r, g, b)

t.colormode(255) 

Mauro = Turtle()
Mauro.shape("circle")
Mauro.speed('fastest')
window.bgcolor("black")
spazio = 0.1

for n in range(0, int(360 / spazio)):
    Mauro.pencolor(random_color())
    Mauro.circle(100)
    Mauro.setheading(n * spazio)

window.exitonclick()