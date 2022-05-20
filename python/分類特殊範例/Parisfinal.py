class Data:#資料庫
    def __init__(self):
        self.animal_name = ''
        self.num = 0
        self.dangerous=''

class Data2: #讀取對照
    def __init__(self):
        self.animal_name = ''
        self.num = 0
        self.dangerous=''
        
class Progrem: #主程式
    def __init__(self):
        self.animal_list = []#記憶體位置
        self.dannum=0
        self.num=0
 
    def __del__(self):
        print('That are the endanger animal list we have now. Bye bye.')
    #歸零
    def business(self):
        self.animal_list = []#記憶體位置
        self.dannum=0
        self.num=0
        
    #加入動物
    def add(self,x):
        self.animal_list.append(x)
        print("Add. Animal: "+x.animal_name+\
              ".\nNumber: "+str(x.num)+\
              "\nEndanger species: "+x.dangerous)
        self.num+=1

    #更新資訊  
    def update(self, x):
        for i in range(0,self.num):
            if x.animal_name == self.animal_list[i].animal_name:
                
                if self.animal_list[i].num<1000:
                    
                    self.dannum-=1

                    
                self.animal_list[i].num=x.num
                print("Update. Animal: "+x.animal_name+\
                      ".\nNumber: "+str(x.num)+\
                      "\nEndanger species: "+x.dangerous)
                
                break
        
    #顯示資訊
    def display(self):
        print('There are '+str(self.dannum)+' animals who are endanger species')
        for i in range(self.num):
            if self.animal_list[i].num<1000:
                print("Animal: "+self.animal_list[i].animal_name+\
                      ".\nNumber: "+str(self.animal_list[i].num))   
        
 


animal = Progrem()
animal.business()

 
while True:
    ctrl = [i for i in input().split(' ',maxsplit=1)]
        
    
    if ctrl[0]=='a':

        a=ctrl[1]
        b=a
        c=eval(input())
        a = Data()
        a.animal_name = b
        a.num = c
        if c<1000:
            a.dangerous = 'Yes'
            animal.dannum+=1
        else:
            a.dangerous = 'No'
            
        animal.add(a)
        
    if ctrl[0]=='u':

        a=ctrl[1]
        b=a
        c=eval(input())
        a = Data2()
        a.animal_name = b
        a.num=c
        if c<1000:
            a.dangerous = 'Yes'
            animal.dannum+=1
        else:
            a.dangerous = 'No'
        animal.update(a)


    if ctrl[0]=='d':
        animal.display()
    if ctrl[0]=='q':
        break

del animal
    
#範例5完整class架構
