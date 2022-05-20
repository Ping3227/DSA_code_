setA={"蘋果", "香蕉", "鳳梨", "芭樂"}
setB={"鳳梨", "蘋果", "水梨", "蓮霧"}
setA.add(input())
setA.add(input())
setA.discard('蘋果')
setB.discard("蓮霧")
setB.add(input())
setB.add(input())
a=list(setA)
a.sort()
print('iA:',a)

a=list(setB)
a.sort()
print('iB:',a)

a=list(setA.union(setB))
a.sort()
print('union:',a)

a=list(setA.intersection(setB))
a.sort()
print('intersection:',a)

a=list(setA.difference(setB))
a.sort()
print('A diff B:',a)

a=list(setB.difference(setA))
a.sort()
print('B diff A:',a)

a=list(setA^setB)
a.sort()
print('A xor B:',a)
