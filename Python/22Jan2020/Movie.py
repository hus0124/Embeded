count = 0
pointcard = True

def membership() :
    global count
    if count >= 5 :
        print("고객님 늘 감사합니다. 멤버쉽 할인이 적용됩니다.")
        count = 0
    else :
        print("예매 성공했습니다.")
        count += 1
        
def ticketset() :
    ticketing = input("예매 하시겠습니까? (y/n) :")

    if ticketing == 'y' or ticketing == 'Y' :
        membership()
    else :
        print("초기 화면으로 돌아갑니다.\n")

print("****Welcome CGV****")
ptcard = input("포인트 카드가 있으신가요? (y/n) :")

if ptcard == 'y' or ptcard =='Y' :
    pointcard = True
else :
    pointcard = False

while True :
    print("****Welcome CGV****")
    print("원하시는 서비스를 선택하세요\n")
    print("1번 : 영화 예매\n2번 : 요금 안내\n3번 : 서비스종료")
          
    select = int(input("번호 선택 : "))

    if select == 1 :
        print("\n1번 : 해치지않아\n2번 : 남산의 부장들\n3번 : 나쁜녀석들 포에버\n")

        movie = int(input("영화 선택 : "))

        if movie == 3 :
            birthday = int(input("출생년도  4자리를 입력하세요 : "))

            if birthday > 2001 :
                print("죄송합니다. 미성년 상영불가 영화입니다.")
            elif birthday < 1961 :

                if pointcard == True :
                    ticketset()
                else :
                    print("장년층 할인으로 예매 금액은 6000원 입니다")
                                    
            else :
                if pointcard == True :
                    ticketset()
                else :
                    print("예매 금액 8000원 입니다")
                
        else :
            birthday = int(input("출생년도  4자리를 입력하세요 : "))

            if birthday < 1961 :
                if pointcard == True :
                    ticketset()
                else :
                    print("장년층 할인으로 예매 금액은 6000원 입니다")
            else :
                if pointcard == True :
                    ticketset()
                else :
                    print("예매 금액 8000원 입니다")

    elif select == 2 :
        print("1960년 이하 출생자 : 6000원")
        print("1961년 이후 출생자 : 8000원")

    else :
        print("감사합니다. 고객님")
        break
            
