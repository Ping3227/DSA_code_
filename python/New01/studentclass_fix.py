
class student:
    def __init__(self,name,gender):
        self.name=name
        self.gender=gender
        self.grades=[]
    def add(self,point):
        self.grades.append(point)
    def avg(self):
        return (sum(self.grades)/len(self.grades))
    def fcout(self):
        total=0
        for i in self.grades:
            if i<60:
                total+=1
        return total
    def show(self):
        print(str(self.name)+\
              '\n%.2f'%(self.avg())+\
              '\n'+str(self.fcout()))
        
s1 = student(input(),input())

s1.add(eval(input()))
s1.add(eval(input()))
s1.add(eval(input()))

s1.show() 

