def matrixMultiPly(a, b):
    c=[]
    for i in range(3):
        c2=[]
        for j in range(3):
            c1=0
            for k in range(3):
                c1+=(a[i][k]*b[k][j])
            c2.append(c1)
        c.append(c2)
    return c
m1=[]
m2=[]
for i in range(3):
    
    m1.append([eval(i) for i in input().split()])
for i in range(3):
    m2.append([eval(i) for i in input().split()])
d=matrixMultiPly(m1,m2)
for i in range(3):
    print(d[i])
