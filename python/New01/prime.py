a=eval(input())
t=0
for i in range (a):
    if (a%(i+1)==0):
        t+=1
if(t==2):
    print(a,"is prime")
else:
    print(a,"is not prime")
