a=[[76,73,85],[88,84,76],[92,82,92],[82,91,85],[72,74,73]]
total=0
highest_avg=0
highest_student=0
for i in range(5):
    summ=0
    print("student",i+1)
    for j in range(3):
        summ+=a[i][j]
        if (j==0):
            print(' 1:',a[i][j])    
        if (j==1):
            print(' 2:',a[i][j])
        if (j==2):
            print(' 3:',a[i][j])
    print(' sum:',summ)
    if(highest_avg<summ):
        highest_avg=summ
        highest_student=i+1
    print(" avg:","%.2f"%(summ/3))
    total+=summ
print('total: ',total,', avg: ','%.2f'%(total/15),sep='')
print("highest avg: student ",highest_student,": ",'%.2f'%(highest_avg/3),sep='')

