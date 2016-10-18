#ifndef _CATALOG_H_
#define _CATALOG_H_

#include "SaleItem.h"

#include <vector>
#include <algorithm>

using namespace std;

class Catalog
{
  private://data member variables declared here
    vector<SaleItem*> catalogVector; //contain pointer of Saleitem
    friend bool compareByTitle(SaleItem* book1, SaleItem* book2);
    friend bool compareByPrice(SaleItem* book1, SaleItem* book2);
    
  public://data member functions declared here
    Catalog(); //default constructor

    //accessor (get) methods    
    void getProductInfo(const int productID);
    SaleItem* getProduct(const int productID);
    
	void printCatalog();
    void sortProductsByTitle();
    void sortProductsByPrice();
};

#endif 
