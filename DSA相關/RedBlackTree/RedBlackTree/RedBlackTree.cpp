// RedBlackTree.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include"Red_Black_Tree.h"
#include <string>
int main()
{
	red_black_tree<int> MY_tree;
	MY_tree.add(55);
	MY_tree.levelorder();
	MY_tree.add(40);
	MY_tree.levelorder();
	
	MY_tree.add(57);
	MY_tree.levelorder();
	MY_tree.add(22);
	MY_tree.levelorder();
	MY_tree.add(31);
	MY_tree.add(65);
	MY_tree.levelorder();
	MY_tree.add(60);
	MY_tree.levelorder();
	MY_tree.add(75);
	MY_tree.levelorder();

	MY_tree.levelorder();
	std::cout << std::endl
		<< "After deleting" << std::endl;
	MY_tree.remove(40);
	MY_tree.levelorder();
	MY_tree.remove(57);
	MY_tree.levelorder();
	std::cout << "Max:" << MY_tree.max() << std::endl;
	std::cout << "Min:" << MY_tree.min() << std::endl;
	MY_tree.inorder();
	MY_tree.postorder();
	MY_tree.preorder();
	/*red_black_tree<std::string> My_tree{};
	std::cout << My_tree.empty() << std::endl;
	std::cout << My_tree.height() << std::endl;
	My_tree.add("abc");
	
	My_tree.add("efg");
	
	My_tree.add("jkl");
	
	std::cout << My_tree.height() << std::endl;
	My_tree.add("avs");
	std::cout << 1 << std::endl;
	My_tree.add("jak");
	std::cout << 2 << std::endl;
	My_tree.add("asda");
	std::cout << 3 << std::endl;
	My_tree.add("ad");
	My_tree.add("aa");
	std::cout << My_tree.height() << std::endl;
	My_tree.add("as");
	My_tree.add("523");

	My_tree.add("23");
	My_tree.add("12");
	My_tree.inorder();
	My_tree.postorder();
	My_tree.preorder();
	My_tree.levelorder();
	std::cout << "Max:" << My_tree.max() << std::endl;
	std::cout << "Min:" << My_tree.min() << std::endl;
	My_tree.remove("avs");
	My_tree.levelorder();
	My_tree.remove("aa");
	My_tree.levelorder();
	My_tree.remove("12");
	std::cout << My_tree.height() << std::endl;
	My_tree.levelorder();
	std::cout << My_tree.contains("avs") << std::endl;
	My_tree.add("avs");
	std::cout << My_tree.contains("avs") << std::endl;
	My_tree.levelorder();
	std::cout << My_tree.empty() << std::endl;
	My_tree.clear();
	My_tree.levelorder();
	std::cout << My_tree.empty() << std::endl;*/
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
