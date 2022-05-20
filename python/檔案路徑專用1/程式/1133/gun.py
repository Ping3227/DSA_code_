a= input()
f1=open(a)
sub=f1.readlines()

subject = [e.split('-')[0]for e in sub]
pistol = 0
smg=0
shotgun=0
AR=0
sniper=0

for i in subject:
    if(i=='PISTOL'):
        pistol+=1
    if(i=='SMG'):
        smg+=1
        
    if(i=='SHOTGUN'):
        shotgun+=1
    if(i=='AR'):
        AR+=1
    if(i=='SNIPER'):
        sniper+=1
print(pistol,smg,shotgun,AR,sniper)
