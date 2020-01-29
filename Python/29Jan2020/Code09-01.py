coffee = []

espresso = ""
water = ""
sugar = ""
cream = ""

order = input("주문하시겠습니까? y or n : ")

if (order =="y" or "Y") :
    
    water = "hot water"

    menu = int(input("원하시는 메뉴를 선택하세요 : \n1.보통 2.설탕 3.블랙 : "))

    if (menu==1) :
        espresso = "espresso"
        sugar = "sugar"
        cream = "cream"
        coffee = [espresso, sugar, cream]
    elif (menu==2) :
        espresso = "espresso"
        sugar = "sugar"
        coffee = [espresso, sugar]
    elif (menu==3) :
        espresso = "espresso"
        coffee = [espresso]
    else :
        print("1~3번 메뉴 중 하나를 선택해주세요")

    coffee.append(water)

    for index, value in enumerate(coffee, start=1):
        print(index, value)

    print("감사합니다.")    

else :
    print("안녕히 가세요")    

        
    


        
