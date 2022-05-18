// Vector_template.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include  <iostream>
#include  "vector.h"
/**/
int main()
{
	Vector<double> abc{};
	for (double i{}; i < 10; i++ ) {
		abc.push_back(i);
	}
	for (int i{}; i < abc.size(); i++) {
		std::cout << abc[i] ;
	}
	std::cout << std::endl;
	for (int i{}; i < 5; i++) {
		abc.pop_back();
	}
	auto def = abc;
	for (int i{}; i < def.size(); i++) {
		std::cout << def[i] ;
	}
	std::cout << std::endl;
	std::cout << def.empty() << std::endl;
	def.clear();
	std::cout << def.empty() << std::endl;

	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	v.push_back(2);
	v.push_back(6);
	v.push_back(2);

	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
	auto iter1 = Remove(v, 2);
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";	
	}
	std::cout << std::endl;
	if (iter1 != v.end()) {
		std::cout << *iter1  << std::endl;
	}
	Vector<int>::Iterator iter2;
	iter2 = Find(v, 6);

	if(iter2 != v.end()){
		std::cout << *iter2 << std::endl;
	}
	else std::cout << "Not found!" << std::endl;
	
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
