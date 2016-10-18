#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
#include <string>

using namespace std;

class Date
{
  private://data member variables declared here
    const int mDay;
    const int mMonth;
    const int mYear;
    
  public://data member functions declared here
    Date(const int day, const int month, const int year);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    
    friend ostream& operator<<(ostream& os, const Date& date);
};

#endif
