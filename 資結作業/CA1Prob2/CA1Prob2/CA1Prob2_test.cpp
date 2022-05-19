#include <iostream>

// the declartion of showprime fuction -- the defination of it is at the end of program 
int* showPrime(int p);

int main() {
	
	int number_to_check{};
	std::cin >> number_to_check;

	//showprime return a  array pointer 
	int * result = showPrime(number_to_check);

	//output the number array with \n seperate them
	std::cout << result[0] << std::endl << result[1] << std::endl;
	return 0;
}