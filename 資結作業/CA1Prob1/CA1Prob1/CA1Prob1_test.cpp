#include <iostream>

//the declartion of the dot product function  --> the defination is at the end of function 
int dotProduct(int a[], int b[], int n);

int main() {

	//using classic array, size must be const 
	const int size_of_array{ 10 };//    < ------  "size setting" 
	int first_array[size_of_array], second_array[size_of_array];

	std::cout << "plz enter the first array (size: " << size_of_array << ")" << std::endl;
	for (int i{}; i < size_of_array; i++) {
		std::cin >> first_array[i];
	}

	std::cout << "plz enter the second array (size: " << size_of_array << ")" << std::endl;
	for (int i{}; i < size_of_array; i++) {
		std::cin >> second_array[i];
	}

	int result = dotProduct(first_array, second_array, 1);
	std::cout << "the dot product of first_array and second_array is " << result << std::endl;


	return 0;
}