def para_func(v1,v2,v3=0) :
    result = 0
    result = v1+v2+v3
    return result

hap = 0

hap = para_func(10,20)
print("매개변수 2개로 함수를 호출한 결과 ==> %d" %hap)

hap = para_func(10,20,30)
print("매개변수 3개로 함수를 호출한 결과 ==> %d" %hap)

def dic_func(**para):
    for k in para.keys():
        print("%s --> %d명입니다." %(k,para[k]))

dic_func(트와이스=9, 블랙핑크=4, BTS=7, 레드벨벳=5)        
