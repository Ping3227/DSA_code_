def Matrix_T(b):
    for i in range(len(b[0])):
        n=1
        for j in b:
            print(j[i],end='')
            if n!=len(b):
                print(end=' ')
            
            n+=1
        print()
            
a=[]
while True:
    c=input()
    if c=='q':
        break
    a.append([eval(i) for i in c.split()])
Matrix_T(a)
