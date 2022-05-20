f1=open('../app/math_list.csv',encoding='big5')
student1=f1.readlines()
f1.close()
num1 =[{'num':e.split(",")[0],
         'name':e.split(",")[1]} for e in student1]


f1=open('../app/english_list.csv',encoding='big5')
student2=f1.readlines()
f1.close()
num2 =[{'num':e.split(",")[0],
        'name':e.split(",")[1]} for e in student2]


mathnum=[e['num'] for e in num1[1::]]


engnum=[e['num'] for e in num2[1::]]


a=list(set(mathnum).intersection(set(engnum)))
a.sort()
b=list(set(mathnum)^(set(engnum)))
b.sort()
c=list(set(mathnum).difference(set(engnum)))
c.sort()
d=list(set(engnum).difference(set(mathnum)))
d.sort()
e=list(set(mathnum).union(set(engnum)))
e.sort()
print(a)
print(b)
print(c)
print(d)
print(e)
