n = eval(input())
A=(input().split(sep=' ',maxsplit = n-1))

if(len(A)%2==1):
    print(A[(len(A)//2)])
else:
    b=(eval(A[(len(A)//2)-1])+eval(A[(len(A)//2)]))/2
    if (b%1==0):
        print(int(b))
    else:
        print(int(b)+1)
