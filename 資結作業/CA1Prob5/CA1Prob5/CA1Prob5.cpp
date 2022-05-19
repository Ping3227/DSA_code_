/************************************************************
		personal data:
		@author 黃緯翔
		@ID B09204045
		@Department 地質科學系
		@Affiliation National Taiwan University

		the target of program :
		wrote a class rectangle ,own attribute name width length primeter,area,and member funcion to get them and set them(consturtor included),then test them in main function
		legth and width should >0

		The intro of the program :
		include three file  ,(.h) contain the declation of all the class memeber ,one of (.cpp) is the defination of class ,and other is test file  

		i add up a memeber function "  showalldata()" to easily check all data
		and i alreday annote it in all three file 

		** notice user must reinclude the head file to use this file

		this code is wrote on my own with Visual studio on windows10
	*************************************************************/
#include<iostream>
#include"CA1Prob5.h"


//member function of rectangle 
//constructor 
rectangle::rectangle(double wd, double lg) :width{ wd }, length{ lg }, perimeter{ (wd + lg) * 2 }, area{ wd*lg }{
};

// function that set both width and length
void rectangle::setDimension(double wd, double lg) {
	// check wheater wd and lg legal
	if (wd <= 0 || lg <= 0) return;

	width = wd;
	length = lg;
	perimeter = (wd + lg) * 2;
	area = wd * lg;
};
// function that set width 
void rectangle::setWidth(double wd) {
	// check wheater wd legal
	if (wd <= 0) return;

	width = wd;
	perimeter = (wd + length) * 2;
	area = wd * length;
};

// function that set length
void rectangle::setLength(double lg) {
	// check wheater lg legal
	if (lg <= 0) return;

	length = lg;
	perimeter = (width + lg) * 2;
	area = width * lg;
};

// function that get width 
double rectangle::getWidth() {
	return width;
};

// function that ger length
double rectangle::getLength() {
	return length;
};

// function that get perimeter ,perimeter = 2*(length +width)
double rectangle::getPerimeter() {
	return perimeter;
};

//funtion that get area , area = length * width
double rectangle::rectangle::getArea() {
	return area;
};

// check the object is square bt checking wheather length == width
bool rectangle::isSquare() {
	return length == width;
};

// this funtion is used to easily check all data
/*void rectangle::showalldata() {
	std::cout << "width:" << getWidth() << std::endl
		<< "length:" << getLength() << std::endl
		<< "perimeter:" << getPerimeter() << std::endl
		<< "Area:" << getArea() << std::endl;
};*/


