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
			cout<<"eCash: �b�����s�b, �Ĥ@���ϥ�!"; 
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
		cout<<"eCash:�п�J�j��0�����B"<<endl;
		return;
		}
	
	Money+=m;
	
		}


void pay(int m){
	if(m>Money){
		cout<<"eCash:�z��������"<<endl;
		return;
		}
	if(m<=0){
		cout<<"eCash:�п�J�j��0�����B"<<endl;
		return;
		}
	Money-=m;
	
	cout<<"eCash:�z��F"<<m<<"��"<<endl;
	}


void display(){
	cout<<"eCash:�z�|��"<<Money<<"��"<<endl;
	}


~eCash(){
	cout<<"eCash: �b���n�X,�w�s��!"<<endl<<" ���¡AByeBye! "<<endl;
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
	cout<<"=== �w��ϥ�eCash === "<<endl
	<<"eCash: �п�J�z���b��: ";
	cin>>c;
	p1.login(c);
	while(1){ 
		<<endl<<endl
		<<c<<"�z�n�A�п�ܶ���:"<<endl
		<<"s: �x��"<<endl
		<<"p: ���O"<<endl
		<<"d: �d�߾l�B"<<endl 
		<<"q: ���}"<<endl
		<<">"; 
		
		cin>>a;
		switch(a){
			case 's':
				cout<<"�п�J�x�s���B:"<<endl;
				cin>>b;
				p1.store(b);
				break;
		
			case 'p':
				cout<<"�п�J���O���B:"<<endl;
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
