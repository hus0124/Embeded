ch =""
a, b = 0,0

while True:
    sensor = input("계산기 작동  y or n : ")

    if (sensor == "n") :
        break
    else :
        a = int(input("첫번째 정수 입력 : "))
        b = int(input("두번째 정수 입력 : "))
        ch = input("원하는 계산 연산자 입력(+ - * / % //) : ")

        if(ch=="+") :
            print("%d %c %d = %d" %(a, ch, b, a+b))
        elif(ch=="-") :
            print("%d %c %d = %d" %(a, ch, b, a-b))
        elif(ch=="*") :
            print("%d %c %d = %d" %(a, ch, b, a*b))
        elif(ch=="/") :
            print("%d %c %d = %d" %(a, ch, b, a/b))
        elif(ch=="%") :
            print("%d %c %d = %d" %(a, ch, b, a%b))
        elif(ch=="//") :
            print("%d %s %d = %d" %(a, ch, b, a//b))
        else :
            print("올바른 연산자 입력 바람")

print("계산기 종료")            
        

        
