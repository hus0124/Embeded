while True : 

    sel = int(input("입력 진수 결정(16/10/8/2) : "))
        
    if sel == 16 :
        num = input("값 입력 : ")
        num10 = int(num, 16)
        break
    elif sel == 10 :
        num = input("값 입력 : ")
        num10 = int(num, 10)
        break
    elif sel == 8 :
        num = input("값 입력 : ")
        num10 = int(num, 8)
        break
    elif sel == 2 :
        num = input("값 입력 : ")
        num10 = int(num, 2)
        break
    else :
        print("입력 진수를 바르게 결정하세요")

   

print("16진수 ==>", hex(num10))
print("10진수 ==>", num10)
print("8진수 ==>", oct(num10))
print("2진수 ==>", bin(num10))
