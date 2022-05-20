a=[eval(i) for i in input().split()]
n= [eval(i) for i in input().split()]
total = 0
while True:
    time=0
    for i in range(a[0]):
        if (n[i]>=a[1]):
            n[i]-=a[1]
            time+=1
            total+=1
    if(time==0):
        break
print(total*a[1])
