from tkinter import *


## 함수 선언 부분 ##
def loadlmage(fname) :
    global inImage, XSIZE, YSIZE
    fp = open(fname,'rb')
    
    for i in range(0,XSIZE) :
        tmpList = []
        for k in range(0, YSIZE) :
            data = int(ord(fp.read(1)))
            tmpList.append(data)
        inImage.append(tmpList)
        
    fp.close()
    
def displaylmage(image) :
    global XSIZE, YSIZE
    for i in range(0,XSIZE) :
        for k in range(0, YSIZE) :
            data = image[i][k]
            paper.put('#%02x%02x%02x' % (data, data, data), (k, i))

## 전역 변수 선언 부분 ##

window = None 

canvas = None

XSIZE, YSIZE = 256, 256

inImage = [] # 2차원 리스트(메모리) 제대로 선언해줘야 한

## 메인 코드 부분 ##

window = Tk()
window.title("흑백 사진 보기")
canvas = Canvas(window, height = XSIZE, width = YSIZE)
paper = PhotoImage(width = XSIZE, height = YSIZE)
canvas.create_image((XSIZE / 2, YSIZE / 2), image = paper, state = "normal")
filename = 'C:/DEV/Python/06Feb2020/RAW/night512.raw'
loadlmage(filename)

# 메모리 --〉화면
displaylmage(inlmage)

canvas.pack()
window.mainloop()
