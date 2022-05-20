b=eval(input())
a = [eval(i)for i in input().split()]
a1= a.copy()
a1.sort()

lowest =a1[0]
highestest =a1[b-1]
print(a.index(highestest)+1,highestest)
print(a.index(lowest)+1,lowest)

