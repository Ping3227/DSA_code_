def speak_number(n):
    try:
        eval(n)
    except NameError:
      return False
    return True

total=0
while True:
    a=input()
    if(speak_number(a)):
        c=eval(a)-int(eval(a))
        total+=c
    if(a=='q'):
        break
print('%.2f'%total)
        
