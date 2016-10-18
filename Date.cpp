//This file contains the implementation code for the Date class data member functions 
#include "Date.h"

Date::Date(const int day, const int month, const int year) :
	mDay(day), mMonth(month), mYear(year) {}
	
int Date::getDay() const 
{ 
return mDay; 
}

int Date::getMonth() const 
{ 
return mMonth; 
}

int Date::getYear() const 
{ 
return mYear; 
}
    
ostream& operator<<(ostream& os, const Date& date)
{
	os << date.getDay() << "." << date.getMonth() << "." << date.getYear();
	return os;
}
