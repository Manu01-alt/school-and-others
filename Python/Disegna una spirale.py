from turtle import Screen, Turtle
window = Screen()

Pippo = Turtle()
Pippo.shape("circle")
Pippo.speed('fastest')
Pippo.pensize(2)
lun = 5

for _ in range (50):
    Pippo.color("orange")
    Pippo.forward(lun)
    lun += 5
    Pippo.right(50)

window.exitonclick()