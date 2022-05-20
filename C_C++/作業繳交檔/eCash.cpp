#include <iostream>
#include "eCash.h"
using namespace std;

void eCash::store(int m){
	if(m<=0){
		cout<<"eCash:請輸入大於0的金額"<<endl;
		return;
		}
	
	Money+=m;
	
}


void eCash::pay(int m){
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

 
void eCash::display(){
	cout<<"您尚有"<<Money<<"元"<<endl;
}

eCash::eCash(){
	Money = 0;
}
eCash::~eCash(){
	cout<<"謝謝，ByeBye! ";
	}
