from turtle import Screen, Turtle
import random
window = Screen()

Pietro = Turtle()
Pietro.shape("turtle")
Pietro.color("blue")
Pietro.pencolor("lightblue")
Pietro.pensize(5)

while True:
    Pietro.teleport(random.randint(0,200),random.randint(0, 200))

window.exitonclick()
