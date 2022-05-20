a=eval(input())
b=eval(input())
for i in range(a):

    for j in range(b):
        
        print ((i+1),'*',(j+1),'=','%2.d'%((i+1)*(j+1)),sep='',end=' ')
    print()
