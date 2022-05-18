// Collider.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <string>
#include<numeric>
int main()
{
	std::string left_or_right;
	std::vector<int> positions;
	int number{};
	std::cin >> number>>left_or_right;
		
	for (int i{}; i < number; i++) {
		int Position;
		std::cin >> Position;
		positions.push_back(Position);
	}
	int start{};
	int smallest{std::numeric_limits<int>::max()};

	for (int i{}; i < number-1; i++) {
		if (left_or_right[i] == 'R'&&left_or_right[i + 1] == 'L') {
			
			if (smallest > (positions[i + 1] - positions[i])/2) {
				smallest = (positions[i + 1] - positions[i]) / 2;
			}
		}
	}
	if (smallest== std::numeric_limits<int>::max())
	std::cout << "-1";
	else {
		std::cout << smallest << std::endl;
	}
	
}
