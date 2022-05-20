f1=open('../app/'+input())
pap= f1.readlines()
f1.close()

cook=[[pap[i].strip(),pap[i+1].strip()]for i in range(len(pap))[::2]]
total=0
for i in range(len(cook)):
    print('chef',cook[i][0],cook[i][1])
    total+=eval(cook[i][1])
print('Total:',total)
avg=total/len(cook)
print('Avg:','%.2f'%avg)
