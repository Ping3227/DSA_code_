def hvtry(n):
    try:
        eval(n)
    except NameError:
        return False
    except SyntaxError:
        return False
    return True
a=input()
if(hvtry(a)):
    print(a,'is a number.')
elif(ord(a)>=97 and ord(a)<=122):
    print(a,'is a lowercase letter.')
    print('swap to capital letter',chr(ord(a)-32),end='.\n')
elif(ord(a)>=65 and ord(a)<=90):
    print(a,'is a capital letter.')
else:
    print(a,'is a punctuation.')
