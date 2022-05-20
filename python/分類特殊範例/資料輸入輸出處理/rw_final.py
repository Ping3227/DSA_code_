import math
def chgscore(a):
    return int(math.sqrt(int(a))*11)

f1=open('./'+input())
score=f1.readlines()
f1.close()
num1 =[{'id':e.split(",")[0],
         'score':e.split(",")[1]} for e in score]

notPass=[int(e['id']) for e in num1[1::]if chgscore(e['score'])<60]
notPass.sort()
for i in range(len(notPass)):
    print(notPass[i],end='')
    if (i+1)!=len(notPass):
        print(' ',end='')
print()
