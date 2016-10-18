#ifndef _BOOK_H_
#define _BOOK_H_

#include "SaleItem.h"

#include <iostream>
#include <string>

class Book : public SaleItem
{
  private://data member variables declared here
    const int mIsbn;
    const string mAuthor;
    const string mPublisher;
  	void print(ostream& os) const;
  
  public://data member functions declared here
  	Book(const string name, const double price, const Date* d, const string category, const int ISBN, const string author, const string publisher);//user-defined overloaded constructor
  
  	//accessor (get) methods
  	int getISBN() const;
  	string getAuthor() const;
  	string getPublisher() const;
  	
  	friend ostream& operator<<(ostream& os, const Book& book);
};

#endif
