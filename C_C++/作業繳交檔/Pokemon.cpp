#include <iostream>
#include"Pokemon.h"
using namespace std;

void Pokemon::Attack(Pokemon &Target){
	if(HpCur<=0){
		cout<<Name<<"is unable to attack"<<endl;
		return;
		}
	if(Target.HpCur<=0){
		cout<<Name<<"can't attack faint target"
			<<Target.Name<<".\n";
		return;
		}
	cout<<Name<<"Attack"<<Target.Name<<" "
		<<Lv<<"Points.\n";
	Target.Defence(Lv);
	}
	
void Pokemon::Defence(int atkp){
	this->HpCur -= atkp;
	if(HpCur<=0){
		cout<<Name<<"is fainted."<<endl;
		HpCur = 0;
		}
	}
void Pokemon::Cure(){
	cout<<Name<<"has restore hea;th.\n";
	HpCur =HpMax;
	}
void Pokemon::ShowInfo(){
	cout<<"Name:"<<Name<<endl;
	cout<<"Lv:"<<Lv<<endl;
	cout<<"HP:"<<HpCur<<"/"
		<<HpMax<<endl<<endl;
	}
void Pokemon::setData(string name,int lv,int hp){
	if(name==""){
		cout<<"Name cant be empty."<<endl;
		name ="No Name";

		}
	if(lv<1){
		cout<<"Lv setting error."<<endl;
		lv=1;
		}
	if(hp<1){
		cout<<"Hp setting error."<<endl;
		hp=1;
		}
	this->Name = name;
	this->Lv = lv;
	HpMax =HpCur =hp;
}
