def YEAR(b):
    b1=(b-3)%10
    b2=(b-3)%12
    c1=['癸','甲','乙','丙','丁','戊','己','庚','辛','壬']
    c2=['亥','子','丑','寅','卯','辰','巳','午','未','申','酉','戌']
    return str(c1[b1]+c2[b2]+'年')
while True:
    a= input()
    if (a=='q'):
        break
    a= eval(a)
    print(a,"=",YEAR(a))
    
