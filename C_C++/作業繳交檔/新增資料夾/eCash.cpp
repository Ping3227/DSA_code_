#include <iostream>

using namespace std;

class eCash{

public:
	
	void store(int m){
	if(m<=0){
		cout<<"eCash:�п�J�j��0�����B"<<endl;
		return;
		}
	
	Money+=m;
	
		}


void pay(int m){
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

 
void display(){
	cout<<"�z�|��"<<Money<<"��"<<endl;
	}

eCash(){
	Money = 0;
	}
~eCash(){
	cout<<"���¡AByeBye! ";
	}
private:
	
	int Money;
};


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
