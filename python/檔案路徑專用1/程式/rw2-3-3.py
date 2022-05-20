a=input()
f1=open('./stores_old'+a+'.csv')
data=f1.readlines()
f1.close()

for i in range(len(data)):
    
    data[i]=data[i].strip().split(',')
   
printdata=(0,3,5,6)

f1=open('./stores_new'+a+'.csv','w',encoding='utf-8')
for i in range(len(data)):
    for j in range(len(data[i])):
        if j in printdata:
            f1.write(data[i][j]+',')
    f1.write('\n')
f1.close()

f1=open('./stores_new'+a+'.csv',encoding='utf-8')
data2= f1.readlines()
f1.close()
for i in range(len(data2)):
    data2[i]=data2[i].strip()
        
    print(data2[i])
