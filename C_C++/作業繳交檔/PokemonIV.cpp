#include <iostream>

using namespace std;


struct Pokemon{
	char name[100];
	int Lv;
	int Hp;
};

void InputData(struct Pokemon &p){
	
	
	
	cin>>p.name;
	cin>>p.Lv;
	cin>>p.Hp;
	
	
	}
	
	
	
void ShowInfo(struct Pokemon p){
	
	cout<<"Name :"<<p.name<<endl;
	cout<<"Lv :"<<p.Lv<<endl;
	cout<<"Hp :"<<p.Hp<<endl<<endl;
	
	}



int main(){
	struct Pokemon p1;
	struct Pokemon p2;
	
	InputData(p1);
	InputData(p2);
	ShowInfo(p1);
	ShowInfo(p2);
	
	
	
	}
