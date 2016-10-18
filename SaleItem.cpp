//This file contains the implementation code for the SaleItem class data member functions 
#include "SaleItem.h"

SaleItem::SaleItem(const string name, const double price, const Date* d, const string category) : 
	mProductID(counter++), mName(name), mPrice(price), releaseDatePtr(d), mCategory(category) {}

//Copy constructor- create a copy of item object
SaleItem::SaleItem(const SaleItem& item) : 
	mProductID(item.getProductID()), mName(item.getName()), mPrice(item.getPrice()), 
	releaseDatePtr(new Date(item.getReleaseDate())), mCategory(item.getCategory()) {}

//Assignment Operator
SaleItem& SaleItem::operator=(const SaleItem& item)//copying item object
{
	if(this == &item) //check for self assignment
	{
		return *this;
	}
	if(item.releaseDatePtr)
	{	
        releaseDatePtr = new Date(*item.releaseDatePtr);// allocate memory for the copy
    }
    else 
	{
        releaseDatePtr = 0;
	} 
    return *this;
	
}


//Destructor
SaleItem::~SaleItem()
{	
	// Deallocate dynamically allocated memory
    delete releaseDatePtr;
    // Set the pointer to null
    releaseDatePtr = 0;
}

int SaleItem::getProductID() const 
{ 
	return mProductID; 
}

string SaleItem::getName() const 
{ 
	return mName; 
}

double SaleItem::getPrice() const 
{
	return mPrice; 
}

void SaleItem::setPrice(const double price) 
{
 	mPrice = price; 
}

Date SaleItem::getReleaseDate() const 
{
	return *releaseDatePtr; 
}

string SaleItem::getCategory() const 
{ 
	return mCategory; 
}

void SaleItem::print(ostream& os) const
{
	os << "  Product ID: " << this->getProductID() << endl
	   << "  Title: " << this->getName() << endl
	   << "  Price: " << this->getPrice() << endl
	   << "  Release Date: " << this->getReleaseDate() << endl
	   << "  Category: " << this->getCategory() << endl;
}

ostream& operator<<(ostream& os,const SaleItem& item)
{
	item.print(os);
	return os;	
}



