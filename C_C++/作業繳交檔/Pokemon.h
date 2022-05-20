#include <iostream>
using namespace std;

class Pokemon{
	
public:
	void ShowInfo();
	void Attack(Pokemon &Target);
	void Defence(int atkp);
	void Cure();
	void setData(string name,int lv,int hp);

private:
	string Name;
	int Lv;
	int HpMax;
	int HpCur;
};
