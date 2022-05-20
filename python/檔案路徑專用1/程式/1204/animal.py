f1=open(input())
pap= f1.readlines()
f1.close()

ani=[[pap[i].strip(),pap[i+1].strip()]for i in range(len(pap))[::2]]
total=0
for i in range(len(ani)):
    if eval(ani[i][1])>=50:
        print(ani[i][0],ani[i][1])
    
