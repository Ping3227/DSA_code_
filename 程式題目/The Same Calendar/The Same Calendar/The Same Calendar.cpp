// The Same Calendar.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
int CountDays(int year);
int main()
{
	int TheYear{};
	int NextYear{};
	std::cin >> TheYear;
	int Extradays{ CountDays(TheYear) };
	NextYear = TheYear + 1;
	for (int Totaldays = 0; ; NextYear++)
	{
		Totaldays = (Totaldays + CountDays(NextYear)) % 7;
		if (Totaldays == 0 && (CountDays(NextYear) == Extradays))
			break;
	}
	std::cout << NextYear << std::endl;
}

int CountDays(int year)
{
	if (year % 400 == 0 || year % 100 != 0 && year % 4 == 0)
		return 2;
	return 1;
}


