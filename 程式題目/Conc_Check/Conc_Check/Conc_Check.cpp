
#include <iostream>
#include <vector>
#include <utility>
#include<string>

using Try = std::vector<std::pair<int ,std::string>>;

int check_Conc(int a, std::string b);

int main()
{
	size_t TryTime{};
	Try InputContainer;
	
	std::cin >> TryTime;

	for (size_t i{}; i < TryTime; i++) {
		int FirstElement{};
		std::string SecondElement{};
		std::cin >> FirstElement >> SecondElement;
		InputContainer.push_back(std::pair<int , std::string>(FirstElement, SecondElement));
	}
	for (const auto&[first, second] : InputContainer) {
		std::cout<<check_Conc(first, second)<<std::endl;
	}
}


int check_Conc(int a, std::string b) {
	//a*b+a+b ==ab
	//=>> b+1 = 10,100,1000 =>b=9,99,999
	std::string bPlus{std::to_string(std::stoi(b)+1)};
	if (bPlus.length() > b.length()) {
		return a * (b.length());
	}
	else {
		return a * (b.length() - 1);
	}
	
}

