num1 = input('숫자1 -->')
num2 = input('숫자2 -->')

try :
    num1 = int(num1)
    num2 = int(num2)
except :
    print('오류발생')
else :
    print(num1, '/', num2, '=', num1/num2)
finally :
    print('무조건 나오는 부분')
