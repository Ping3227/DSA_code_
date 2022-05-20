d={}
b1=0
for i in range(eval(input())):
    a=input().split()
    
    if(a[0] in d):
        d[a[0]]=int(d[a[0]])+int(a[1])
    else:
        d[a[0]]=eval(a[1])
    if(int(d[a[0]])>b1):
        b1=int(d[a[0]])
        b2=a[0]
    
print(b2,d[b2])
    
