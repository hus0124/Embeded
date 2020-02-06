inFp, outFp = None, None

inStr = ""

inFp = open("C:/Windows/win.ini", "r")
outFp = open("C:/DEV/Python/06Feb2020/data4.txt","w")

inList = inFp.readlines()

for inStr in inList:
    outFp.writelines(inStr)

inFp.close()
outFp.close()
print("--파일이 정상적으로 복사되었음--")
