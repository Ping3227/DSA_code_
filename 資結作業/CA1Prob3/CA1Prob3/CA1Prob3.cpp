/*************************************************************
	personal data:
	@author 黃緯翔
	@ID B09204045
	@Department 地質科學系
	@Affiliation National Taiwan University

	the target of program :
	input two long int ,find whether the first one the multiple of the second one

	The intro of the program :
	input two long int:larger or equal than 1,  should follow the order that the second number is smaller than the first number  
	using %operator to know wheather the numbers satisfy the conditon 
	the result would be true or false rather than 1 and 0 (in test code )

	this code were wrote on my own with Visual studio on windows10
	*************************************************************/


// the declarion of function is multiple
bool isMultiple(long n, long m) {
	// check wheather n and m illegal ,n,m must larger than/equal than 1
	if (n < m || n < 1 || m < 1) return false;
	return (n%m)==0;
};

// if n is multiple of m  =>  n%m ==0  