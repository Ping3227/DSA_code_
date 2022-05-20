a=[]
total=0
while True:
    b=eval(input())
    if(b==-1):
        break
    if (b>30):
        total+=b
    a.append(b)
print(a)
a.sort()
print(a)
print(total)
