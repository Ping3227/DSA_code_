x=eval(input())
def return2num(n=0):
    c=1
    d=0
    for i in range(n):
        c*=(i+1)
        d+=(i+1)    
    return c,d

ans=return2num(x)
print(ans[0])
print(ans[1])
