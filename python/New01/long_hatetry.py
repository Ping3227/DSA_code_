s='''漢皇重色思傾國御宇多年求不得楊家有'''
s2=['漢皇', '重色思', '傾國', '御宇', '多年']

aw=[]
dw={}
for i in range(len(s2)):
    #print('\n',i,list(i),'\n')
    if(len(s2[i]) not in aw):
        aw.append(len(s2[i]))
        
        dw[len(s2[i])]=[]
        dw[len(s2[i])].append(s2[i])
        #print('\n',dw[len(s2[i])],'\n')
            #dw[len(i)].append(list(i))
    elif(s2[i] not in dw):
            #dw[len(i)]=dw[len(i)]+list(i)
        dw[len(s2[i])].append(s2[i])

aw.sort()
for j in aw:
    
    aw1=[]
    dw1={}
    
    for e in dw[j]:#range(len(dw)) dw[aw[j]]
        if(s.count(e) not in aw1):
            aw1.append(s.count(e))
            dw1[s.count(e)]=[]
            dw1[s.count(e)].append(e)
            #dw[len(i)].append(list(i))
        elif(e not in dw1):
            #dw[len(i)]=dw[len(i)]+list(i)
            dw1[s.count(e)].append(e)
    aw1.sort()
    aw1.reverse()
    for m in aw1:
        
        for n in dw1[m]:
            print(n,m)
