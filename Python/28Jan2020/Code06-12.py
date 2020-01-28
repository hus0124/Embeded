i, total = 1, 0

while True :
    if i % 3 == 0 :
        i += 1
        continue

    total += i
    i += 1

    if (i > 100) :
        break
print("1에서 %d까지 3의 배수 제외한 합계는 %d" %(i-1, total))
    
