/************************************************************
		personal data:
		@author 黃緯翔
		@ID B09204045
		@Department 地質科學系
		@Affiliation National Taiwan University

		the target of program :
		wrote a class flower ,own attribute name ,petal, price,and member funcion to get them and set them(consturtor included),then test them in main function
		price and petal must >=0 in program

		The intro of the program :
		this program include three file class declartion(.h) class defination(.cpp) and test file (.cpp)

		i add up a memeber function " print_all_data()" to easily check all data 
		i already annotated it in all three file 

		** notice user must reinclude the head file to use this file

		this code were wrote on my own  with Visual studio on windows10
	*************************************************************/

#include"CA1Prob4.h"
#include <string>


// the defination of member funciton 
//constructor
flower::flower(std::string n, int pt, double pr) :name{ n }, petal{ pt }, price{ pr }{
};

//member fubction setname
void flower::setName(std::string n) {
	name = n;
};
// member function setpetal 
void flower::setPetal(int pt) {
	// check wheather pt is legal or not 
	if (pt < 0) return;
	petal = pt;
	
};

//member function setprice 
void flower::setPrice(double pr) {
	// check wheather pr is legal or not 
	if (pr < 0) return;
	price = pr;
};

//member function return member 'name'
std::string flower::getName() {
	return name;
};
// member function return member 'petal'
int flower::getPetal() {
	return petal;
};

//member function return member 'price'
double flower::getPrice() {
	return price;
};

// this function " print_all_data()"  is build for easily print out the data 
/*
void flower::print_all_data() {
	std::cout << "name:" << getName() << std::endl
		<< "petal:" << getPetal() << std::endl
		<< "price:" << getPrice() << std::endl;
};
*/
