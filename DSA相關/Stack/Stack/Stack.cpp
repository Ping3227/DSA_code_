#include <iostream>
#include "Stack_array.h"
#include <vector>


int main()
{
	Stack<int> data(10);
	Stack<int> copy{ data };
	Stack<int> copy2 = data;
	Stack<int> move{ Stack<int>(5) };
	Stack<int> move2 = Stack<int>(5);

	for (int i{}; i < 10; i++) {
		data.push(i);
		std::cout<<data.top()<<"size:"<<data.size();
		std::cout << std::endl;
	}
	
	std::cout<<"empty"<<data.empty()<<std::endl;
	data.print_stack();

	std::cout << "size"<<data.size() << std::endl;
	
	int a = data.size();
	
	for (int i{}; i < data.size(); i++) {
		std::cout << data.top()<< "size:" << data.size();
		std::cout << std::endl;
		data.pop();

	}
	
	std::cout << "empty" << data.empty() << std::endl;
	data.print_stack();


	std::vector<int> test(5, 10);
	for (int i{}; i < test.size(); i++) {
		test.pop_back();
	}
	std::cout << "size" << test.size() << std::endl;
}