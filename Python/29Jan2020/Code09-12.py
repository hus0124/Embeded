def para_func(*para):
    result = 0
    for i in para :
        result = result + i

    return result

hap = 0

hap = para_func(10,20)
print("매개변수 2개로 함수를 호출한 결과 ==> %d" %hap)

hap = para_func(10,20,30)
print("매개변수 3개로 함수를 호출한 결과 ==> %d" %hap)

hap = para_func(10,20,30,40,50,60,70,80,90,100)
print("매개변수 3개로 함수를 호출한 결과 ==> %d" %hap)
