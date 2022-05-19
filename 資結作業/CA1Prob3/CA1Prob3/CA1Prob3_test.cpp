#include <iostream>

// the declarion of ismultiple function -- the defination is at the end of the program 
bool isMultiple(long n, long m);

int main() {


	//using long rather than int 
	long number1{}, number2{};
	std::cout << "input two number,the program will show you wheather first number multiple of second number" << std::endl;
	std::cin >> number1;
	std::cin >> number2;
	
	// output true of false rather than 1 and 0
	if (isMultiple(number1, number2)) {
		std::cout << "true";

	}
	else std::cout << "false ";
	return 0;
}