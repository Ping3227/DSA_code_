n = input().split()
t=20
t+=(eval(n[0])//2)*(eval(n[1])-eval(n[2]))
if (eval(n[0])%2!=0):
    t+=eval(n[1])
else:
    t+=eval(n[2])
print (t)
