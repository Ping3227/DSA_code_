#include <iostream>
#include <string>
#include"CA1Prob4.h"


// the code here is used to test member function
int main() {

	//test constuctor and get..function
	flower myflower{ "Nodding Trillium",3 ,75.0 };
	std::cout << "name:" << myflower.getName() << std::endl
		<< "petal:" << myflower.getPetal() << std::endl
		<< "price:" << myflower.getPrice() << std::endl;

	flower myflower2{ "Prairie Rose",5 ,100.0 };
	flower myflower3{ "Bluebell",6  ,85.0 };
	//myflower2.print_all_data();
	//myflower3.print_all_data();


	std::string  change_string{};
	int change_petal{};
	double change_price{};

	// test set name here 
	std::cout << "name setting ,plz input a new name " << std::endl;
	std::cin >> change_string;
	myflower.setName(change_string);
	//myflower.print_all_data();

	// test set petal here 
	std::cout << "petal setting ,plz input a new petal " << std::endl;
	std::cin >> change_petal;
	myflower.setPetal(change_petal);
	//myflower.print_all_data();


	// test set price here 
	std::cout << "price setting ,plz input a new price " << std::endl;
	std::cin >> change_price;
	myflower.setPrice(change_price);
	//myflower.print_all_data();
	return 0;
}

