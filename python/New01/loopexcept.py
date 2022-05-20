total=0 
while True:
    try:
        a= eval(input())
        if a<=0:
            continue
        for i in range(a):
            b=1
            for j in range(i+1):
                b*=(j+1)
            total+=b
        print(total)

    except NameError:
        continue
    except TypeError:
        continue
    break


