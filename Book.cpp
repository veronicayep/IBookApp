//This file contains the implementation code for the Book class data member functions 
#include "Book.h"

Book::Book(const string name, const double price, const Date* d, const string category, const int ISBN, const string author, const string publisher) :
	SaleItem(name, price, d, category), mIsbn(ISBN), mAuthor(author), mPublisher(publisher) {}
	
int Book::getISBN() const 
{
	return mIsbn;
}
  	
string Book::getAuthor() const 
{
	return mAuthor; 
}
  	
string Book::getPublisher() const 
{
	return mPublisher;
}


void Book::print(ostream& os) const
{
	SaleItem::print(os); // Overridden print data member functions
	os << "  ISBN: " << this->getISBN() << endl
	   << "  Author: " << this->getAuthor() << endl
	   << "  Publisher: " << this->getPublisher() << endl;
}

ostream& operator<<(ostream& os, const Book& book)
{
	book.print(os);
	return os;
}
