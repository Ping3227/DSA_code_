b=[]
 
while True:
    a= input()
    if(a=='-1'):
        break
    for l in a:
        if(97<=ord(l) and ord(l)<=122):
            
            c=(ord(l)-32)
 
            print(chr(c),end='')
        
        else:
            print(l,end='')
    print()
 
