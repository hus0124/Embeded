i, total = 0,0

for i in range(1,101,1) :
    total += i

    if (total >= 1000) :
        print("합계는 %d, %d번에서 1000 이상 시점" %(total,i))
        break     
    
