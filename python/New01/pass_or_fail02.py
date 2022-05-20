clas= eval(input())
if (clas!=1 and clas!=2):
    print("role error")
else:
    point =eval(input())
    if (point<0 or point>100):
        print("score error")

    elif (clas==1 and point>=60):
        print("pass")
    elif(clas==2 and point>=70):
        print("pass")
    else:
        print("fail")
    
