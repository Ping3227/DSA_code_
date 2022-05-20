ye=0
n=0
notsure=0
for i in range(eval(input())):
    a = input()
    if(a=='no' or a=='yes'):
        ye+=1
    elif(a=="NO" or a=="YES"):
        n+=1
    else:
        notsure+=1
print(ye,n,notsure)
