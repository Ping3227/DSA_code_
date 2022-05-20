a=[]

for i in range(5,0,-1):
    
    a.append(input())

for i in range(5):
    
    b= eval(a[i])
    print(b,'*'*b,sep='\t')
