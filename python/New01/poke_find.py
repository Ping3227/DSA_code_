class Pokemon:
    alpoke=[]
    
    def __init__(a,name,lv,hp):
        a.name = name
        a.lv=lv
        a.hp =hp
        Pokemon.alpoke.append(a)
    def show_info(a):
        print('Name:',a.name)
        print('Lv:',a.lv)
        print('HP:',a.hp)  
p1=Pokemon(input(),int(input()),int(input()))
p2=Pokemon(input(),int(input()),int(input()))
p3=Pokemon(input(),int(input()),int(input()))
b=0

for i in Pokemon.alpoke:
    if i.lv>=b:
        b=i.lv
        c=i
c.show_info()
