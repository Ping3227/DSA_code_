class Data:
    def __init__(self):
        self.ai=0
        self.bi=0
        self.ci=0
        self.bad='good'
                      
c=[]        
for i in range(eval(input())):
    b=[eval(j) for j in input().split()]

    i=Data()
    i.ai=b[0]
    i.bi=b[1]
    i.ci=b[2]
    
    c.append(i)
d=eval(input())
c[d-1].bad='bad'
while True:
    t=0
    for i in c:
        if i.bad=='bad':
            for j in c:
                
                if i.ai>j.ai and i.bi>j.ci and j.bad=='good':
                    j.bad='bad'
                    
                    t+=1
    if t==0:
        break
    
count=0
for i in c:
    if i.bad=='bad':
        count+=1

print(count)
