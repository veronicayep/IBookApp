#ifndef _SALEITEM_H_
#define _SALEITEM_H_

#include "Date.h"

#include <iostream>
#include <string>

using namespace std;

static int counter;

class SaleItem
{
  private://data member variables declared here
    const int mProductID;
    const string mName;
    double mPrice;
    const Date* releaseDatePtr;
    const string mCategory;	

  protected:
  	virtual void print(ostream& os) const; //polymorphism
    
  public://data member functions declared here
    SaleItem(const string name, const double price, const Date* d, const string category); //user-defined constructor
    SaleItem(const SaleItem&); //Copy constructor
    SaleItem& operator=( const SaleItem& ); //Assignment operator
    ~SaleItem();
	
	//mutator (set) methods 
	void setPrice(const double price);
	
	//accessor (get) methods
    int getProductID() const;
    string getName() const;
    double getPrice() const;
    Date getReleaseDate() const;
    string getCategory() const;  

    friend ostream& operator<<(ostream& os, const SaleItem& item);
};

#endif
