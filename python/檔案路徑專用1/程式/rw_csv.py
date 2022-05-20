f1=open('../app/score.csv')
student1=f1.readlines()

score =[{'id':e.split(",")[0],
         'math':e.split(",")[1],
         'eng':e.split(",")[2]} for e in student1]


mathPass=[e['id'] for e in score[1::] if int(e['math'])>=60]
mathPass.sort()
print(mathPass)

engPass=[e['id'] for e in score[1::] if int(e['eng'])>=60]
engPass.sort()
print(engPass)
b=list(set(mathPass).difference(set(engPass)))
b.sort()
print(b)
print(len(score)-1)
'''
f1=open('../app/score.csv')
student=f1.readlines()
for i in range(len(student)):
    student[i]=student[i].strip()
    student[i]=student[i].split(',')

mathPass=[e[0] for e in student if int(e[1])>=60]
print(mathPass)'''

f1.close()
