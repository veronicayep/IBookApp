#ifndef _MAGAZINE_H_
#define _MAGAZINE_H_

#include "SaleItem.h"

#include <iostream>
#include <string>

class Magazine : public SaleItem //implementing inheritance relationship between SaleItem and Magazine
{
  private://data member variables declared here
    const string mPublisher;
    const int mIssueNumber;
  	void print(ostream& os) const;
    
  public://data member functions declared here
  	Magazine(const string name, const double price, const Date* d, const string category, const string publisher, const int issueNumber);
  	string getPublisher() const;
  	int getIssueNumber() const;
  	
  	friend ostream& operator<<(ostream& os, const Magazine& magazine); //overloading operator<<
};

#endif
