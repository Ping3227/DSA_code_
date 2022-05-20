class Pokemon:
    alpoke=[]
    clasfy=[]
    def __init__(a,name,lv,hp):
        a.name = name
        a.lv=lv
        a.hp =hp
        Pokemon.alpoke.append(a)
    def show_info(a):
        print('Name:',a.name)
        print('Lv:',a.lv)
        print('HP:',a.hp)
        print()
    def alinfm(a,n):
        if n=='0':
            for i in Pokemon.alpoke:
                i.show_info()

        if n=='1':
            for i in Pokemon.alpoke:
                Pokemon.clasfy.append(i.name)
                Pokemon.clasfy.sort()
                
            for i in Pokemon.clasfy:
                for k in Pokemon.alpoke:
                    if i==k.name:
                        k.show_info()
                        Pokemon.alpoke.remove(k)
                        
            
        if n=='2':
            for i in Pokemon.alpoke:
                Pokemon.clasfy.append(i.lv)
                Pokemon.clasfy.sort()
                
            for i in Pokemon.clasfy:
                for k in Pokemon.alpoke:
                    if i==k.lv:
                        k.show_info()
                        Pokemon.alpoke.remove(k)
        if n=='3':
            for i in Pokemon.alpoke:
                Pokemon.clasfy.append(i.hp)
                Pokemon.clasfy.sort()
                
            for i in Pokemon.clasfy:
                for k in Pokemon.alpoke:
                    if i==k.hp:
                        k.show_info()
                        Pokemon.alpoke.remove(k)
for j in range(eval(input())):           
    j=Pokemon(input(),int(input()),int(input()))          


Pokemon.alinfm(0,input())
