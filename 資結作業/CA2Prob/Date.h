/**
 * this progam is used to record the date 
 * include member function to construct with string and parmeter 
 * ,to compare two date or show the detail like date in month , is leap or not e.t.c 
 * I add three class memeber day, month and year to record the date
 * also add an int array to show how many days in a month
 *
 * @author 			黃緯翔 Huang-wei-hsiang
 * @ID 				B09204045
 * @Department 		地質科學系 Geosciences
 * @Affiliation 	National Taiwan University
 *
 * Date.h
 * version 1.0
 * this code is worte on my own by c++ on visual studio
 */


#ifndef DATE_H
#define DATE_H

#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

class Date {
private:
	int the_day{};
	int the_month{};
	int the_year{};
	int month_days[12]{31,28,31,30,31,30,31,31,30,31,30,31};
public:
	Date(int month, int day, int year);
	Date(const string& s);
	bool isLeapYear(int year);
	int daysInMonth(int month, int year);
	bool isValidDate(int month, int day, int year);
	string toString();
	bool isBefore(const Date& d);
	bool isAfter(const Date& d);
	bool isEqual(const Date& d);
	int dayInYear();
	int difference(const Date& d);

};

#endif