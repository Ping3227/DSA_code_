b=[]
 
while True:
    a= input()
    if(a=='-1'):
        break
    else:
        b.append(a)
for l in range(len(b)):
    for i in b[l]:
        if(97<=ord(i) and ord(i)<=122):
            
            c=(ord(i)-3)
            if (c<97):
                c+=26
 
            print(chr(c),end='')
        elif(65<=ord(i) and ord(i)<=90):
            c=ord(i)-3+32
            if (c<65):
                c+=26

            print(chr(c),end='')
        else:
            print(i,end='')
    if(l==len(b)-1):
        print()
    else:
        print(end=' ')
