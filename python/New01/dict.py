
d=dict(zip(('P','M','H'),('Pikachu','Mickey Mouse','Hello kitty')))
while True:
    a=input()
    if (a=="-1"):
        break
   
    if (a in d):
        print (d[a])
    else:
        print(a,end=' ')
        ndata =input("does not exist. Enter a new one:\n")
        d[a]= ndata
