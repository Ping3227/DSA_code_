def PrintData(**Data):
    
    if 'uid' in Data.keys():
        print('The user id:',Data['uid'])

    if 'name' in Data.keys():
        print('The username:',Data['name'])

    if 'age' in Data.keys():
        print('The user age:',Data['age'])

PrintData(uid=input(),name=input(),age=input())
PrintData(uid=input(),name=input())
PrintData(name=input())
