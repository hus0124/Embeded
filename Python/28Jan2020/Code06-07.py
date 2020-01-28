i, k, guguLine = 0, 0, ""

for i in range(2, 10) :
    guguLine = guguLine + ("#    %d단   #" % i)

print(guguLine)

for i in range(1, 10) :
    guguLine =""
    for j in range(2,10) :
        guguLine = guguLine + str("%2d X %2d = %2d" %(j, i, j*i))
    print(guguLine)    
