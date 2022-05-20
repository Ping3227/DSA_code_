a=eval(input())
import os,shutil
if os.path.exists('files'):
    shutil.rmtree('files')
os.mkdir('files')

os.chdir('files')
for i in range(1,a+1):
    os.mkdir('f'+str(i))
b=os.listdir()
b.sort()
print(b)
os.rename('f1','folder1')
b=os.listdir()
b.sort()
print(b)
os.removedirs('folder1')
b=os.listdir()
b.sort()
print(b)
for i in os.listdir():
    os.rmdir(i)
os.chdir('../')
os.rmdir('files')
