a=input()
f1=open('./stores_old'+a+'.csv')
data=f1.readlines()
f1.close()
DATA =[e.split(",")[0]+','+
       e.split(",")[3]+','+
       e.split(",")[5]+','+
       e.split(",")[6] for e in data]

f1=open('./stores_new'+a+'.csv','w',encoding='utf-8')
f1.writelines('\n'.join(DATA))
f1.close()


'''f1=open('./stores_new'+a+'.csv',encoding='utf-8')
prdata=f1.readlines()
f1.close()'''
for e in DATA:
    print(e+',')

