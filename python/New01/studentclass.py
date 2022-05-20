def top(*students):
    high=0
    
    for i in students:
        c=i.avg()
        if c>=high:
            high=c
            highone=i
    print('Top Student:')
    return highone
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
        print('Name: '+str(self.name)+\
              '\nGender: '+str(self.gender)+\
              '\nGrades: '+str(self.grades)+\
              '\nAvg: '+str(self.avg())+\
              '\nFail Number: '+str(self.fcout())+\
              '\n')
        
s1 = student("Tom","M")
s2 = student("Jane","F")
s3 = student("John","M")
s4 = student("Ann","F")
s5 = student("Peter","M")
s1.add(80)
s1.add(90)
s1.add(55)
s1.add(77)
s1.add(40)
s2.add(58)
s2.add(87)
s3.add(100)
s3.add(80)
s4.add(40)
s4.add(55)
s5.add(60)
s5.add(60)
s1.show()
s2.show() 
s3.show()
s4.show() 
s5.show()
top_student = top(s1,s2,s3,s4,s5)
top_student.show()
