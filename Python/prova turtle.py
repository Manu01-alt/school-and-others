from turtle import Turtle, Screen
window = Screen()
Indu = Turtle()
Indu.shape("turtle") #le shape sono turtle, circle, classic, square, triangle, arrow
Indu.color("blue")
Indu.speed(0)
Indu.penup()
Indu.goto(0,0)
Indu.pendown()
for n in range(3,100):
    for _ in range(n):
        Indu.forward(100)
        Indu.left(360/n)
window.exitonclick()

#metto la turtle al centro