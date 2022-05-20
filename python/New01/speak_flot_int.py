imt=1
floot=1
while True:
    a=input()
    if (a=="q"):
        break
    else:
        b=eval(a)
        if(type(b)==int):
            imt*=b
        if(type(b)==float):
            floot*=b
print('%.2f\n%d'%(floot,imt))
if (floot==imt):
    print("Float = Int")
if (floot>imt):
    print("Float > Int")
if (floot<imt):
    print("Float < Int")    
    
    
    
        
        
        
        
