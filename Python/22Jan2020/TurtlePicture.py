import turtle
t = turtle.Pen()

t.speed(10)
size = 5
colorsize = 0
color = ["#FF0000", "#FF5E00", "#FFBB00", "#FFE400", "#ABF200", "#1DDB16", "#00D8FF", "#0054FF", "#0100FF", "#5F00FF"]

for i in range(999):
    t.pencolor(color[colorsize])
    t.right(90)
    t.forward(size)
    size = size + 5
    colorsize = colorsize + 1
    if colorsize >= 10 :
        colorsize = 0
    
    

turtle.mainloop()
