inFp = None
inStr = ""

inFp = open("C:/DEV/Python/06Feb2020/data1.txt", "r")

inStr = inFp.readline()

print(inStr, end="")

inStr = inFp.readline()

print(inStr, end="")

inStr = inFp.readline()

print(inStr, end="\n")

inFp = open("C:/DEV/Python/06Feb2020/data2.txt", "r", encoding="UTF8")

inStr = inFp.readline()

print(inStr, end="")

inStr = inFp.readline()

print(inStr, end="")

inStr = inFp.readline()

print(inStr, end="")

inFp.close()            
