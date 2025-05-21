from turtle import Screen, Turtle
import turtle as t

def draw_square(size):
    Gennaro.begin_fill()
    for _ in range(4):
        Gennaro.forward(size)
        Gennaro.left(90)
    Gennaro.end_fill()

def draw_triangle():
    Gennaro.begin_fill()
    for _ in range(3):
        Gennaro.forward(100)
        Gennaro.left(120)
    Gennaro.end_fill()

def draw_rectangle():
    Gennaro.begin_fill()
    for _ in range(2):
        Gennaro.forward(20)
        Gennaro.left(90)
        Gennaro.forward(49)
        Gennaro.left(90)
    Gennaro.end_fill()

def draw_circle():
    Gennaro.begin_fill()
    Gennaro.circle(20)
    Gennaro.end_fill()

window = Screen()
window.bgcolor("skyblue")

Gennaro = Turtle()
Gennaro.shape("turtle")
Gennaro.speed('fastest')
Gennaro.hideturtle()

Gennaro.fillcolor("yellow")
draw_square(100)

Gennaro.penup()
Gennaro.goto(0, 100)
Gennaro.pendown()

Gennaro.fillcolor("red")
draw_triangle()

Gennaro.penup()
Gennaro.goto(70, 55)
Gennaro.pendown()

Gennaro.fillcolor("skyblue")
draw_square(20)

Gennaro.penup()
Gennaro.goto(40, 0)
Gennaro.pendown()

Gennaro.fillcolor("brown")
draw_rectangle()

window.exitonclick()

