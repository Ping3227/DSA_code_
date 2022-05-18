// 數字龍捲風.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
int main()
{	
	int matrix_size{};
	int choice{};// left 0   up 1   right 2   down 3
	int x{}, y{};
	
	std::vector<std::vector<int>> matrix;
	std::cin >> matrix_size >> choice;
	matrix.resize(matrix_size, std::vector<int>(matrix_size));
	x = y = matrix_size / 2 ;
	
	for (int i{}; i < matrix_size; i++) {
		for (int j{}; j < matrix_size; j++) {
			std::cin >> matrix[i][j];
		}
	}
	if (matrix_size == 1) {
		std::cout << matrix[0][0] << std::endl;
		return 0;
	}
	int upper_row{ x + 1 }, lower_row{ x - 1 };
	int upper_col{ y + 1 }, lower_col{ y - 1 };
	while ( y >= 0 && y <= matrix_size-1 && x >= 0 && x<= matrix_size-1) {
		std::cout << matrix[x][y];
		switch (choice)
		{
		case 0: //left 
			y -= 1;
			if (y == lower_col) {
				choice = 1;
				lower_col--;
			}
			break;
		case 1: //upper 
			x -= 1;
			if (x == lower_row) {
				choice = 2;
				lower_row--;
			}
			break;
		case 2: //right
			y += 1;
			if (y == upper_col) {
				choice = 3;
				upper_col++;
			}
			break;
		case 3: //down
			x += 1;
			if (x == upper_row) {
				choice = 0;
				upper_row++;
			}
			break;
		default:
			break;
		}
	}
	std::cout << std::endl;
	
		
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
