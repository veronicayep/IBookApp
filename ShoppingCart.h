//This file contains the implementation code for the ShoppingCart class data member functions 
#ifndef _SHOPPING_CART_H_
#define _SHOPPING_CART_H_

#include "Book.h"
#include "Magazine.h"
#include "SaleItem.h"

#include <vector>

using namespace std;

class ShoppingCart
{
  private://data member variables declared here
    vector<SaleItem*> cartVector;
    double calculateTotal();
    
  public://data member functions declared here
  	void addItem(SaleItem* item);
    void addItem(Book& book); //overloading function
    void addItem(Magazine& magazine);
	void printViewCart();
    void checkout();
};

#endif 
