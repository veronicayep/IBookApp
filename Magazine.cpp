//This file contains the implementation code for the Magazine class data member functions 
#include "Magazine.h"

Magazine::Magazine(const string name, const double price, const Date* d, const string category, const string publisher, const int issueNumber) :
	SaleItem(name, price, d, category), mPublisher(publisher), mIssueNumber(issueNumber) {}
  	
string Magazine::getPublisher() const 
{ 
return mPublisher; 
}

int Magazine::getIssueNumber() const 
{ 
return mIssueNumber; 
}

void Magazine::print(ostream& os) const // Overridden print data member functions
{
	SaleItem::print(os);
	os << "  Publisher: " << this->getPublisher() << endl
	   << "  Issue Number: " << this->getIssueNumber() << endl;	
}

ostream& operator<<(ostream& os, const Magazine& magazine)
{
	magazine.print(os);
	return os;
}
