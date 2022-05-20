n = input().split()
L= eval(n[0])
S= eval(n[1])
d=L-S
addd=0
minnus=0
if (d>=0):
    addd=d
    minnus =d*2
    if (minnus>5 ):
        
        addd-=(minnus//5)*2
        minnus =minnus%5
    
else:
    addd=-d
    minnus = -d*3
    if (addd>2):
        minnus-=(addd//2)*5
        addd=addd%2
    
print (addd+minnus)
