#include <iostream>

using namespace std;

class eCash{

public:
	
	void store(int m){
	if(m<=0){
		cout<<"eCash:請輸入大於0的金額"<<endl;
		return;
		}
	
	Money+=m;
	
		}


void pay(int m){
	if(m>Money){
		cout<<"您的錢不夠"<<endl;
		return;
		}
	if(m<=0){
		cout<<"eCash:請輸入大於0的金額"<<endl;
		return;
		}
	Money-=m;
	
	cout<<"您花了"<<m<<"元"<<endl;
	}

 
void display(){
	cout<<"您尚有"<<Money<<"元"<<endl;
	}

eCash(){
	Money = 0;
	}
~eCash(){
	cout<<"謝謝，ByeBye! ";
	}
private:
	
	int Money;
};


int main(){
	eCash p1;
	char a;
	int b;
	while(1){ 
		cout<<"=== 歡迎使用eCash ==="<<endl<<endl
		<<"您好，請選擇項目:"<<endl
		<<"s: 儲值"<<endl
		<<"p: 消費"<<endl
		<<"d: 顯示餘額"<<endl 
		<<"q: 離開"<<endl
		<<">"; 
		
		cin>>a;
		switch(a){
			case 's':
				cout<<"請輸入儲存金額:";
				cin>>b;
				p1.store(b);
				break;
		
			case 'p':
				cout<<"請輸入消費金額:";
				cin>>b;
				p1.pay(b);
				break;
			case 'd':
				p1.display();
				break;
			case 'q':
				return 0;	
		}
		system("pause");
		system("cls");
	
		} 
	}
