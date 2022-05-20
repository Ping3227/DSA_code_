def P(n,m):
    c=1
    for i in range(n,n-m,-1):
        c*=i
    return c
        
def C(n,m):
    c=1
    for i in range(n,n-m,-1):
        c*=i
    for i in range(m):
        c/=(i+1)
    return int(c)
    
