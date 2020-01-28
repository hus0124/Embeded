money, c500, c100, c50, c10, change = 0,0,0,0,0,0
p50000, p10000, p5000, p1000 = 0,0,0,0

money = int(input("교환할 돈은 얼마? : "))

p50000 = money // 50000
money %= 50000

p10000 = money // 10000
money %= 10000

p5000 = money // 5000
money %= 5000

p1000 = money // 1000
money %= 1000

c500 = money // 500
money %= 500

c100 = money // 100
money %= 100

c50 = money // 50
money %= 50

c10 = money // 10
money %= 10

change = money

print("50000원짜리 ==> %d장\n" %p50000)
print("10000원짜리 ==> %d장\n" %p10000)
print("5000원짜리 ==> %d장\n" %p5000)
print("1000원짜리 ==> %d장\n" %p1000)
print("500원짜리 ==> %d개\n" %c500)
print("100원짜리 ==> %d개\n" %c100)
print("50원짜리 ==> %d개\n" %c50)
print("10원짜리 ==> %d개\n" %c10)
print("바꾸지 못한 잔돈 ==> %d\n" %change)


