def Matrix_Inverse(b):
    det=(b[0][0]*b[1][1])-(b[1][0]*b[0][1])
    if (det==0):
        print('none')
    else:    
        print(format((b[1][1]/det+0.0001),'0.1f'),format((-b[0][1]/det+0.0001),'0.1f'))
        print(format((-b[1][0]/det+0.0001),'0.1f'),format((b[0][0]/det+0.0001),'0.1f'))

    
a=[]
a.append([eval(i) for i in input().split()])
a.append([eval(i) for i in input().split()])
    
Matrix_Inverse(a)
