from turtle import Screen, Turtle
import turtle as t

def draw_square():
    for _ in range(4):
        Salvatore.forward(100)
        Salvatore.right(90)

window = Screen()
t.colormode(255)
Salvatore = Turtle()
Salvatore.hideturtle()
Salvatore.speed('fastest')


x = -500
y = 500
r = 0
space = -50

for i in range(10):
    Salvatore.teleport(x, y)
    Salvatore.pencolor((r,0,0))
    Salvatore.fillcolor((r,0,0))
    Salvatore.begin_fill()
    draw_square()
    Salvatore.end_fill()
    x += 25
    y -= 25
    r += 25




window.exitonclick()

