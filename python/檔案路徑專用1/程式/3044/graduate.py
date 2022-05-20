a= input()
f1=open(a)
sub=f1.readlines()

subject = [{'clas':e.split(',')[0],
            'typ':e.split(',')[1],
            'point':e.split(',')[2],
            'pass':e.split(',')[3].strip()}for e in sub[1::]]

r=0
e=0
for i in subject:
    if i['typ']=='E'and i['pass']!='F':
        e+=eval(i['point'])
    if i['typ']=='R'and i['pass']!='F':
        r+=eval(i['point'])
        
print('Required:',r)
print('Elective:',e)

if r<72 and e<28:
    print('N')
    print('Student still needs to complete',72-r,'required credits &',28-e,'elective credits for graduation.')
elif r<72 and e>=28:
    print('N')
    print('Student still needs to complete',72-r,'required credits for graduation.')
elif r>=72 and e<28:
    print('N')
    print('Student still needs to complete',28-e,'elective credits for graduation.')

else:
    print('Y')
