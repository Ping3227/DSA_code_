/*************************************************************
	personal data:
	@author 黃緯翔
	@ID B09204045
	@Department 地質科學系
	@Affiliation National Taiwan University

	the target of program :
	input a number and return it and 0 in array if it is prime
	or return it as both next prime smaller and bigger than it if it is not prime

	The intro of the program :
		input a number
		by division the number by other numbers less than it,we know wheather a number is a prime or not
		*  only need to test the number from 2 to [n/2](floor funciton) 
		because 2 is the smallest prime => factor less than 2 is not allow ,except 1 => factor larger than n/2 are, too
		final result would be a array return,and print out as two number that show each number in index 0 and 1 of array  

	this code were wrote on my own with Visual studio on windows10
	*************************************************************/



//the showprime function
int* showPrime(int p) {
	// construct a array that 
	int return_array[2]{};
	//check wheather int a illegal number(p<=1) ,if true return [0,0]
	if (p <=1) {
		return return_array;
	}
	// count how many factor we found now ,except 1
	int count{};

	//to find weather p is prime 
	for (int i{ 2 }; i < p / 2; i++) {
		if (p%i == 0) {
			count++;
			break;
		}
	}
	// count == 0 show p is a prime
	if (count == 0) {
		return_array[0] = p;
		return return_array;
	}
	//if not, find the larger prime and smaller prime next 
	int large_num{ p+1 }, small_num{p-1};
	// find large prime
	while (true) {
		count = 0;
		for (int i{ 2 }; i < large_num / 2; i++) {
			if (large_num%i == 0) {
				count++;
				break;
			}
		}
		// count == 0 show largenum a prime ,if != 0 largenum++ and test again
		if (count == 0) {
			return_array[1] =large_num;
			break;
		}
		large_num++;
	}
	//find small prime
	while (true) {
		count = 0;
		for (int i{ 2 }; i < small_num / 2; i++) {
			if (small_num%i == 0) {
				count--;
				break;
			}
		}
		// count == 0 show smallnum a prime ,if != 0 smallnum-- and test again
		if (count == 0) {
			return_array[0] = small_num;
			break;
		}
		small_num--;
	}
	return return_array;
}

// the return type would be [p,0] when p is a prime
// while return [smaller prime, larger prime ] when p was not a prime 
