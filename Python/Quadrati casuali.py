from turtle import Screen, Turtle
import turtle as t
import random

def random_color():
    r = random.randint(0, 255)
    g = random.randint(0, 255)
    b = random.randint(0, 255)
    return (r, g, b)

def draw_square():
    Ernesto.begin_fill()
    for _ in range(4):
        Ernesto.forward(50)
        Ernesto.left(90)
    Ernesto.end_fill()

t.colormode(255)

window = Screen()  

print("Inserire il numero di quadrati da disegnare:")   
n = int(input())

x = random.randint(-300, 300)
y = random.randint(-300, 300)

Ernesto = Turtle()
Ernesto.hideturtle()
Ernesto.speed('fastest')

for i in range(n):
    Ernesto.penup()
    Ernesto.goto(x, y)
    Ernesto.pendown()
    Ernesto.fillcolor((random_color()))
    draw_square()
    x = random.randint(-300, 300)
    y = random.randint(-300, 300)








window.exitonclick()