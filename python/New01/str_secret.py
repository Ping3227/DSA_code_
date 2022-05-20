a=eval(input())
b=[]
c=0

for i in range(a):
    b.append(input())

for i in range(a):
    e=0
    for l in b[i]:
        f=ord(str(l).upper())-64
        e+=f
    print(str(b[i]).upper(),'=',e)
    if(e>c):
        c=e
        d=str(b[i]).upper()

print(d,'is the key.')
    
