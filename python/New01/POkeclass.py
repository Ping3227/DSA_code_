count=0
a=[]
class Pokeworld:#主程式
    def __init__(self):
        self.Name=''
        self.Lv=0
        self.HpCurrent=0
        self.HpMax=0
    #def Pokemon(self,Name):  
    def Attack(self,tar):#攻擊
        if (self.HpCurrent<=0):
            print(tar.Name,"Win,",self.Name,"Lose.\n"+\
                  self.Name,"is unable to attack.")
            return 0
        if tar.HpCurrent<=0:
            return 0
        print(self.Name,"Attack",tar.Name,self.Lv,'Points.')
        tar.Defence(self.Lv)
        
    def Defence(self,dmg):#防禦
        self.HpCurrent-=dmg
        if self.HpCurrent<=0:
            self.HpCurrent=0
            print(self.Name,"Seriously Injured.")
            
    def Cure(self):#治癒
        self.HpCurrent=self.HpMax
        
    def setData(self,name,lv,hp):
        self.Name=name
        self.Lv=lv
        self.HpCurrent=hp
        self.HpMax=hp
        
    def ShowInfo(self):
        print("Name:",self.Name)
        print("Lv:",self.Lv)
        print("HP:",str(self.HpCurrent)+"/"+str(self.HpMax))
    def __del__(self):
        return
M = Pokeworld()
M.setData("Mewtwo",30,300)
for i in range(eval(input())):
    i=Pokeworld()
    a.append(i)
    i.setData(input(),int(input()),int(input()))
for i in a:
    count+=1
    print("#"+str(count))
    while True:
        if i.Attack(M)==0:
            break
        if M.Attack(i)==0:
            break
    M.ShowInfo()
    i.ShowInfo()
    print()
    M.Cure()
