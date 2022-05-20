a =input()
b=[]
k=0
while True:
    c=input()
    if (c=='q'):
        break
    b.append(c)
a=a.lower()
for i in range(len(b)):
    if (b[i]==a):
        print('Yes',i+1)
        k=1
        break
if(k==0):
    print("No",len(b))
