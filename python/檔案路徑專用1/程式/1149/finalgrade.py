f1=open(input())
data=f1.readlines()
f1.close()
for i in range(len(data)):
    data[i]=data[i].strip().split(',')
    if i>0:
        a=0
        for j in range(4):
            a+=eval(data[i][j+1])
           
        a=(a*0.7/4)+eval(data[i][5])*3/4
        if (a<60 and eval(data[i][5])==40):
            a =60
        print(data[i][0],'%.2f'%a)
        

