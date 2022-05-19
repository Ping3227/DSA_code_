/**
 * this progam is used to record the date
 * include member function to construct with string and parmeter
 * ,to compare two date or show the detail like date in month , is leap or not e.t.c
 * I add three class memeber day, month and year to record the date
 * also add an int array to show how many days in a month
 *
 * @author 			黃緯翔  Huang-wei-hsiang
 * @ID 				B09204045
 * @Department 		地質科學系 Geosciences
 * @Affiliation 	National Taiwan University
 *
 * Date.cpp
 * version 1.0
 * this code is worte on my own by c++ on visual studio
 */

																				  
																				  
#include "Date.h"																  
																				  
// constuctor 											  
Date::Date(int month, int day, int year) {										  
	if (isValidDate(month, day, year) ){										  
		the_day=day;
		the_month=month;
		the_year=year;
	}
	else {
		cout<<"error input"<<endl;
		exit(0);
	}
}
  

 // use built-in function in string( find to get the index of '/'
//substr to get day,month and year. stoi to transform string into number)
Date::Date(const string& s) {
	int n{}, m{};
	m= s.find('/');
	int month = stoi(s.substr(n,m)); // get char from index 0 to m-1
	
	n = m;
	m = s.find('/',n + 1);       //iterate to next '/'index
	int day = stoi(s.substr(n+1,m-n-1));// get char from n+1 to m-1
	int year = stoi(s.substr(m+1)); // get char from index m+1 to end
	// if not valid number end the program
	if (isValidDate(month, day, year)) {
		the_day = day;
		the_month = month;
		the_year = year;
	}
	else {
		cout << "error input" << endl;
		exit(0);
	}
}


/**************************************************
A leap year is any year divisible by 4, except that a year divisible by 100 is not a leap
year, except that a year divisible by 400 is a leap year after all.
so i use condition operator to do this 
if year a multiple of 400 it must be leap,
if year a multiple of 100 but not 400 it must not leap
if year a multiple of 4 but not 100 it must be leap
******************************************************/
bool Date::isLeapYear(int year) {
	
	return (year%400==0)?true:
		(year%100==0)?false:
		(year%4==0)?true:false;                       
};


  /*************************************************** 
   February contains 28 days most years, but 29 days during a leap year.
   i build a array member in this class 
   use this function to recognize wheather the month February
   if not, return the corresbonding day in the month 
   if so, recognize wheather it is leap year February
   if so, return 29 if not return 28
   **************************************************/
int Date::daysInMonth(int month, int year) {

    return (month!=2)? month_days[month-1]:
		(isLeapYear(year))? 29:28;
}


  /*************************************************** 
   year must be 1-9999(1 to 4 bits and not nagtive)
   month most be 1-12
   day must be 1-the day in that month (need to consider leap year Feburary) 
   ****************************************************/
bool Date::isValidDate(int month, int day, int year) {
	
	if(year <= 0||year>9999)return false;
	
	if (month > 12 || month < 1) return false;
	
	if (day<1 || day>daysInMonth(month, year)) return false;
	
	return true;
}


  /***************************************************
  use string's bulit-in opeartor+ to add string with '/'
  ***************************************************/
string Date::toString() {
	
	string date_string=to_string(the_month)+'/'+to_string(the_day)+'/'+to_string(the_year);
	return date_string;  
}



/****************************************
compare the year then month then date by conditon operator 
****************************************/
bool Date::isBefore(const Date& d) {
	
	return (the_year>d.the_year)?false:
		(the_year != d.the_year)?true:
		(the_month > d.the_month) ? false :
		(the_month != d.the_month) ? true :
		(the_day < d.the_day) ? true :false ;
}
  

bool Date::isAfter(const Date& d) {
    return (the_year < d.the_year) ? false :
		(the_year != d.the_year) ? true :
		(the_month < d.the_month) ? false :
		(the_month != d.the_month) ? true :
		(the_day > d.the_day) ? true : false;
};                        
  
  
  
//if month year day are not eaual ,the date wont be eaul 
bool Date::isEqual(const Date& d){
	  return (the_year==d.the_year && the_month==d.the_month && the_day==d.the_day);
};                        

// test if the_year leap year,if so return 366,else return 365
int Date::dayInYear() {
	return (isLeapYear(the_year))?366:365;                     
};
  

// the method i use is let two date come to same year(by minus the year diffirent)
// then use same method to the month (i ignore leap year here)
// after dealt with the days, check wheater date leap year and after march
// if so add back the difference we ignore ,then the answer come out 
int Date::difference(const Date& d) {
	int total_differ{};
	//add/minus year difference，minus/add the year between two date(include the year of small one date)
	if (the_year > d.the_year) {
		for (int tmp_year = the_year; tmp_year != d.the_year; tmp_year--){
			total_differ += (isLeapYear(tmp_year-1) ? 366 : 365);
		}
	}
	else {
		for (int tmp_year = the_year; tmp_year != d.the_year; tmp_year++){
			total_differ -= (isLeapYear(tmp_year) ? 366 : 365);
		}
	}
	// add/minus  month difference，delete/minus the month between two date(include the month of small one date)
	if (the_month > d.the_month) {
		for (int tmp_month = the_month; tmp_month != d.the_month; tmp_month--) {
			total_differ +=month_days[tmp_month-2];
		}
	}
	else {
		for (int tmp_month = the_month; tmp_month != d.the_month; tmp_month++) {
			total_differ -= month_days[tmp_month-1];
		}
	}
	//add/minus  day difference，
	total_differ += (the_day - d.the_day);
	//i suppose all the day are same whether it is leap year or not 
	// so if the day of date is bigger/equal than march.1 
	//1 need to add/minus 1 for the complement of number i have ignore
	if (isLeapYear(the_year) && the_month > 2 ) total_differ++;
	if (isLeapYear(d.the_year) && (d.the_month > 2)) total_differ--;
	
	return total_differ;
};

