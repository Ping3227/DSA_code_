a=input().split('-')
b=['z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y']
for i in a:
    alpha=eval(i)%26
    time =eval(i)//26
    if (alpha==0):
        time-=1
    print(b[alpha]*(time+1),end='')

print()
    
