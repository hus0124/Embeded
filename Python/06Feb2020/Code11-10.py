inFp, outFp = None, None

inStr = ""

inFp = open("C:/Windows/notepad.exe", "rb")
outFp = open("C:/DEV/Python/06Feb2020/notepad.txt", "wb")

while True :
    inStr = inFp.read(1)
    if not inStr :
        break
    outFp.write(inStr)

inFp.close()
outFp.close()
print("이진파일 정상 복사")
