class Data:
    def __init__(self):
        self.product_name = ''
        self.price = 0
        self.number_of_sold = 0

class Data2:
    def __init__(self):
        self.product_name = ''
        self.number = 0
        self.price=0
        
class OFM: #Old_Farmer_Market
    def __init__(self):
        self.Product_list = []
        self.item_type = 0
        self.profit = 0
        self.total_item_sold = 0
 
    def __del__(self):
        print('Thanks for visiting Old Farmer Market. Wish you have a good day. Bye bye.')
    #歸零
    def business(self):
        self.Product_list = []
        self.item_type = 0
        self.profit = 0
        self.total_item_sold = 0
 
    #進行加入新產品
    def add(self,x):
        self.Product_list.append(x)
        print("Added. Product: "+x.product_name+\
              ".\nSell price: "+str(x.price))
        self.item_type+=1

    #賣出產品
    def sell(self,x):
        for i in range(self.item_type):
            if x.product_name==self.Product_list[i].product_name:
                self.Product_list[i].number_of_sold+=x.number
                print("Sold. Product: "+x.product_name+\
                      ".\nNumber of sold: "+str(x.number))
                self.profit += x.number * self.Product_list[i].price;
                self.total_item_sold += x.number;
                break

            
    def update(self, x):
        for i in range(0,self.item_type):
            if x.product_name == self.Product_list[i].product_name:
                self.Product_list[i].price=x.price
                print("Updated. Product: "+x.product_name+\
                      ".\nSell Price: "+str(x.price))
                break

    #顯示目前賣出產品的數量和目前的總利潤
    def display(self):
        for i in range(self.item_type):
            print("Product: "+self.Product_list[i].product_name+\
                  ".\nTotal number of sold:",self.Product_list[i].number_of_sold)   
        print("Total product sold: "+str(self.total_item_sold)+"\nProfit:",self.profit)
 


Old = OFM()
Old.business()
print("Welcome to Old Farmer Market, what can I help you?")
 
while True:
    ctrl = [i for i in input().split(' ',maxsplit=1)]
        
    
    if ctrl[0]=='a':

        a=ctrl[1]
        b=a
        a = Data()
        a.product_name = b
        a.price = eval(input())
        a.number_of_sold = 0
        Old.add(a)
        
    if ctrl[0]=='u':

        a=ctrl[1]
        b=a
        a = Data2()
        a.product_name = b
        a.price=eval(input())
        Old.update(a)

            
    if ctrl[0]=='s':
        a=ctrl[1]
        b=a
        a = Data2()
        a.product_name = b
        a.number = eval(input())
        Old.sell(a)

    if ctrl[0]=='d':
        Old.display()
    if ctrl[0]=='q':
        break

del Old
    
