#ifndef  CA1PROB4
#define CA1PROB4

#include<iostream>
#include<string>

// the class flower -- the defination of member funciton is at the end of program  
class flower {
private:
	std::string name;
	int petal;
	double price;
public:
	
	// Constructor.
	flower(std::string n, int pt, double pr);
	
	// Set the name of the flower.
	void setName(std::string n);
	
	// Set the petal number of the flower.
	void setPetal(int pt);
	
	// Set the price of the flower.
	void setPrice(double pr);
	
	// Return the name of the flower.
	std::string getName();
	
	// Return the petal number of the flower.
	int getPetal();
	
	// Return the price of the flower.
	double getPrice();
	
	// easily check all data
	//void print_all_data();
};

#endif // ! CA1PROB4
