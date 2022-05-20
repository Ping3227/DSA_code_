a=[]
while True:

    n= eval(input())
    if(n==-1):
        break
    else:
        a.append(n)

for i in range(len(a)-1,-1,-1):
    print (a[i])
    print ('\n'*(a[i]-1))
print("--------------------")
