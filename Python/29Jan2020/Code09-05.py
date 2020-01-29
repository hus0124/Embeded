def calc(v1, v2, op) :
    result = 0

    if op == '+' :
        result = v1 + v2
    elif op == '-' :
        result = v1 - v2
    elif op == '*' :
        result = v1 * v2
    elif op == '/' :
        result = v1 / v2

    return result

res = 0
var1, var2, oper = 0.0, 0.0, ""

oper = input("계산을 입력하세요(+ - * /) : ")

var1 = float(input("첫 번째 수 입력 : "))
var2 = float(input("두 번째 수 입력 : "))
res = calc(var1, var2, oper)

print("%.3f %c %.3f = %.3f" % (var1, oper, var2, res))          
