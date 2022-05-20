f1=open('../app/'+input())
p1= f1.readline().split()
f1.close()
f1=open('../app/'+input())
p2= f1.readline().split()
f1.close()
b=[]
for i in p1:
    b.append(eval(i))
for i in p2:
    b.append(eval(i))


b.sort()
for i in b:
    print(i,end=' ')
print()
