#include <iostream>
#include "CA1Prob5.h"

//this code is used to test 
int main() {
	//test constructor and get...function
	rectangle my_rectangle{20,10};
	std::cout << "width:" << my_rectangle.getWidth() << std::endl
		<< "length:" << my_rectangle.getLength() << std::endl
		<< "perimeter:" << my_rectangle.getPerimeter() << std::endl
		<< "Area:" << my_rectangle.getArea() << std::endl;


	double input1{}, input2{}, input3{}, input4{};

	//test setdimension
	std::cout << "set both width and length,plz input width first then input length" << std::endl;
	std::cin >> input1 >> input2;
	my_rectangle.setDimension(input1, input2);
	//my_rectangle.showalldata();

	//test set width
	std::cout << "set width,plz input width:" << std::endl;
	std::cin >> input3;
	my_rectangle.setWidth(input3);
	//my_rectangle.showalldata();

	//test set length
	std::cout << "set length,plz input legth:" << std::endl;
	std::cin >> input4;
	my_rectangle.setLength(input4);
	//my_rectangle.showalldata();


	return 0;
}

