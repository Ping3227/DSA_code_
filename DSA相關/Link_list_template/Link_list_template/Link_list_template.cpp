// Link_list_template.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include "Linked_list.h"
#include <iostream>

int main()
{
	Linked_list<int> List;
	
	List.push_front(1);
	List.push_front(2);
	List.push_front(3);
	List.print_list();
	List.pop_front();
	List.pop_front();
	List.print_list();
	List.pop_front();
	List.pop_front();
	List.print_list();


	List.push_back(1);
	List.push_back(2);
	List.push_back(3);
	List.print_list();
	List.reverse();
	List.print_list();
	List.clear();
	List.print_list();

	List.push_back(1);
	List.push_back(2);
	List.push_back(3);
	List.pop_back();
	List.pop_back();
	List.print_list();
	List.pop_back();
	List.pop_back();
	List.print_list();

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
