f1=open(input())
p1= f1.readlines()
f1.close()
lst=[[i.split(',')[0],eval(i.split(',')[1].strip()) ]for i in p1]
box=[]
for i in lst:
    if i[0].lower() not in box:
        box.append(i[0].lower())
box.sort()
for i in box:
    a=0
    for j in lst:
        if j[0].lower()==i:
            
            a+=j[1]
    print(i,a,sep=',')

