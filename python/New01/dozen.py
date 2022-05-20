n = int(input())

dozen = n//12
mod = n%12

print (dozen,'dozen',end='')

if mod:
    print (' and',mod)
