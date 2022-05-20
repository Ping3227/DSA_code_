def Matrix_Inverse(b):
    det=(b[0][0]*b[1][1])-(b[1][0]*b[0][1])
    if (det==0):
        print('none')
    else:    
        print(round_up((b[1][1]/det)),round_up((-b[0][1]/det)))
        print(round_up((-b[1][0]/det)),round_up(b[0][0]/det))
def round_up(c):
    print(c,c*10,round(c*10),(c*10)//1)
    if c<0 and ((c*10)//1)-c*10==-0.5:
        return round(((c*10)+0.5)/10.0)
    else:
        return round(c*10)/10.0
a=[]
a.append([eval(i) for i in input().split()])
a.append([eval(i) for i in input().split()])
    
Matrix_Inverse(a)
