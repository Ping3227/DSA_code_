def speak_number(n):
    try:
        eval(n)
    except NameError:
      return False
    return True

b=[]
while True:
    a= input()
    if (a=='q'):
        break
    
    if(speak_number(a)):
        b.append(eval(a))
    
    else:
        print('Please Enter Numbers Only')
c=b.copy()
print(b)
b.sort()
print(b)
print(b[::-1])
print(c)
