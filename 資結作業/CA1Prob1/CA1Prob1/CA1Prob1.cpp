/*************************************************************
	personal data:
	@author 黃緯翔
	@ID B09204045
	@Department 地質科學系
	@Affiliation National Taiwan University

	the target of program :
	input two array and find their dot product

	The intro of the program :
	input two array 
	the arraysize n is already setted up in test file 
	user should change the size in test code
	final result would be the total sum of a[i]·b[i] i=1 -> n  also called dot product of a and b

	this code were wrote on my own with Visual studio on windows10 
	*************************************************************/


//the defination of the dot product function -- is used to add up all a[i]*b[i] i=1,2,3..n
int dotProduct(int a[], int b[], int n) {

	int total{};
	for (int i{}; i < n; i++) {
		total += a[i] * b[i];
	}
	return total;
}