#include <iostream>
#include "eCash.h"
//=== �w��ϥ�eCash ===
//�z�n�A�п�ܶ���: s: �x�� p: ���O d: ��ܾl�B q: ���} >
using namespace std;
int main(){
	eCash p1;
	char a;
	int b;
	while(1){ 
		cout<<"=== �w��ϥ�eCash ==="<<endl<<endl
		<<"�z�n�A�п�ܶ���:"<<endl
		<<"s: �x��"<<endl
		<<"p: ���O"<<endl
		<<"d: ��ܾl�B"<<endl 
		<<"q: ���}"<<endl
		<<">"; 
		
		cin>>a;
		switch(a){
			case 's':
				cout<<"�п�J�x�s���B:";
				cin>>b;
				p1.store(b);
				break;
		
			case 'p':
				cout<<"�п�J���O���B:";
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
