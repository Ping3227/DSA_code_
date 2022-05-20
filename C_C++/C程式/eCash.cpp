#include <iostream>
#include "eCash.h"
using namespace std;

void eCash::store(int m){
	if(m<=0){
		cout<<"eCash:�п�J�j��0�����B"<<endl;
		return;
		}
	
	Money+=m;
	
}


void eCash::pay(int m){
	if(m>Money){
		cout<<"�z��������"<<endl;
		return;
		}
	if(m<=0){
		cout<<"eCash:�п�J�j��0�����B"<<endl;
		return;
		}
	Money-=m;
	
	cout<<"�z��F"<<m<<"��"<<endl;
}

 
void eCash::display(){
	cout<<"�z�|��"<<Money<<"��"<<endl;
}

eCash::eCash(){
	Money = 0;
}
eCash::~eCash(){
	cout<<"���¡AByeBye! ";
	}
