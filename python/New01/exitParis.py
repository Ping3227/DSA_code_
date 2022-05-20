class Data:
    Animal_list=[]
    dgrnum=0
    def __init__(self,num):
        self.num = num
        self.dangerous='NO'
        Data.Animal_list.append(self)
        print(type(self))
        if num <1000:
            dgrnum+=1
            self.dangerous='Yes'
        print('Add. Animal:',b,end='.\n')
        print('Number:',num)
        print('Endanger species:',self.dangerous)
        
    def change(self,num):
        print(self)
        print(type(self.num),type(num))
        if self.num<1000 and num >=1000:
            dgrnum-=1
            self.dangerous='No'
        if self.num >=1000 and num <1000:
            dgrnum+=1
            self.dangerous='Yes'
        
        tra.num=num
        
        print('Update. Animal:',b,end='.\n')
        print('Number:',num)
        print('Endanger species:',tra.dangerous)
    
while True:
    a=input()
    if a=='a':
        b=input()
        b=Data(eval(input()))
        
        
    if a=='u':
        b=input()
        b.change(eval(input()))
    if a=='d':
        print('There are',Data.dgrnum,'animals who are endanger species')
    if a=='q':
        print('That are the endanger animal list we have now. Bye bye.\n')
        break

