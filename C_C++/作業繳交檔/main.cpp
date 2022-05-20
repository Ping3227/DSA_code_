#include <iostream>
#include "eCash.h"
//=== 歡迎使用eCash ===
//您好，請選擇項目: s: 儲值 p: 消費 d: 顯示餘額 q: 離開 >
using namespace std;
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
