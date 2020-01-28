i, total = 0, 0

while i < 11 :
    total+=i
    i+=1

print("0에서 %d까지 합 = %d" %(i-1, total))    

while True :
    a = int(input("첫번째 수 입력: "))
    b = int(input("두번째 수 입력: "))
    total = a+b
    print("합계 = %d" %total)
