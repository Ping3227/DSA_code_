d={'T':'Top','H':'Hoodie','B':'Backpack'}
#「T」、「H」或「B」時，「Top」、HoodieBackpack」
while True:
    a=input()
    if(a=="-1"):
        break
    if(a=="-2"):
        c=[]
        e=[]
        for i in d.keys():
           c.append(i)
        c.sort()
        for i in range(len(d)):
           e.append(d[c[i]])
        
        print('keys:',c)
        
        print('values:',e)
        d.values()
    elif(a=="-3"):
        b=input()   
        if(b in d):
            d.pop(b)
        else:
            print("key",b,"does not exist, cannot delete.")
        
    elif(a in d):
        print(d[a])
    else:
        print(a,"does not exist. Enter a new product category:")
        d[a]=input()
    
