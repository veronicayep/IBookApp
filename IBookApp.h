#ifndef _IBOOK_APP_H_
#define _IBOOK_APP_H_

#include "Catalog.h"
#include "ShoppingCart.h"

using namespace std;

class IBookApp
{
  private://data member variables declared here
  	Catalog mCatalog;
	ShoppingCart mCart;
	enum mOptions { VIEW_CATALOG, VIEW_CART, CHECKOUT }; //enumeration declaration
	enum mCatalogOptions { RETURN, MORE_INFO, ADD_ITEM }; 
	enum mSortOptions { SORT_BY_TITLE, SORT_BY_PRICE, SORT_BY_ID}; 
	int printMenuOptions();
    void printViewCatalogOptions(); 
    void sortOption();
	
  public://data member functions declared here
    void run();

};

#endif 
