n= input().split()
animal =eval(n[0])
feets= eval(n[1])
chik = animal

rabit= 0

for i in range(animal+1):
    if ((chik*2+rabit*4)==feets):
        print ("YES\n",chik,' ',rabit,sep="")
        break
    elif(chik>0):
        
        chik -= 1
        rabit+=1
        
    else:
        print("NO")
        break
