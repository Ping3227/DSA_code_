dct=dict(zip(('-----','.----','..---','...--','....-','.....','-....','--...','---..','----.'),('0','1','2','3','4','5','6','7','8','9')))
def transform(a):
    lst=[]
    for i in a:
        c=i.strip()
        
        if c in dct:
            lst.append(dct[c])
        else:
            lst.clear()
            lst.append('error')
            break
    k=''.join(lst)
    return k
    answer.append(lst)
answer=[]
while True:
    d=input()
    if d =='-1':
        break
    b=[i for i in d.split()]
    
    answer.append(transform(b))
    
for i in answer:
    for j in i:
        print(j,end='')
    print()
