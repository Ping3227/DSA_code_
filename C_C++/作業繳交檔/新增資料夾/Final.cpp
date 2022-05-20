#include <iostream>
#include <fstream>
using namespace std;

class eCash{

public:
	
	
	
	void login(char n){
		ifstream fin;
		
		fin.open(n".txt");
		
		if(!fin.is_open()){ 
			ofstream fout;
			cout<<"eCash: 帳號不存在, 第一次使用!"; 
			fout.open(n".txt");
			fout.close();
			Money =0;
			return;   
			}
		fin>>d;
		Money = d;
		fin.close();
		}
	
	void logout(char n){
		fout.open(n".txt");
		endl<<Money;
		fout.close();
		} 
	

	void store(int m){
	if(m<=0){
		cout<<"eCash:請輸入大於0的金額"<<endl;
		return;
		}
	
	Money+=m;
	
		}


void pay(int m){
	if(m>Money){
		cout<<"eCash:您的錢不夠"<<endl;
		return;
		}
	if(m<=0){
		cout<<"eCash:請輸入大於0的金額"<<endl;
		return;
		}
	Money-=m;
	
	cout<<"eCash:您花了"<<m<<"元"<<endl;
	}


void display(){
	cout<<"eCash:您尚有"<<Money<<"元"<<endl;
	}


~eCash(){
	cout<<"eCash: 帳號登出,已存檔!"<<endl<<" 謝謝，ByeBye! "<<endl;
	}
private:
	
	int d;
	int Money;
	char  ID;
};


int main(){
	eCash p1;
	char a,c;
	int b;
	cout<<"=== 歡迎使用eCash === "<<endl
	<<"eCash: 請輸入您的帳號: ";
	cin>>c;
	p1.login(c);
	while(1){ 
		<<endl<<endl
		<<c<<"您好，請選擇項目:"<<endl
		<<"s: 儲值"<<endl
		<<"p: 消費"<<endl
		<<"d: 查詢餘額"<<endl 
		<<"q: 離開"<<endl
		<<">"; 
		
		cin>>a;
		switch(a){
			case 's':
				cout<<"請輸入儲存金額:"<<endl;
				cin>>b;
				p1.store(b);
				break;
		
			case 'p':
				cout<<"請輸入消費金額:"<<endl;
				cin>>b;
				p1.pay(b);
				break;
			case 'd':
				p1.display();
				break;
			case 'q':
				p1.logout(c);
				return 0;	
		}
		system("pause");
		system("cls");
	
		} 
	}
