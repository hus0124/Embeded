def myFunc():
    print('함수를 호출함.')

gVar = 100

def main():
    print('메인 함수 부분이 실행됩니다.')
    myFunc()
    print('전역 변수 값:', gVar)
    
if __name__ == '__main__' :
    main()
    
