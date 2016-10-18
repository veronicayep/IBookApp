#include "ShoppingCart.h"

#include <iomanip>

void ShoppingCart::addItem(SaleItem* item)
{
	cartVector.push_back(item);	
}

void ShoppingCart::addItem(Book& book) //overloading function
{
	cartVector.push_back(&book);	
}

void ShoppingCart::addItem(Magazine& magazine) //overloading function
{
	cartVector.push_back(&magazine);	
}

double ShoppingCart::calculateTotal()
{
	double total = 0;
	for (vector<SaleItem*>::iterator it = cartVector.begin(); it != cartVector.end(); it++)
    {
       	total += (*it)->getPrice();
    }
	return total;
}

void ShoppingCart::printViewCart()
{
	if (cartVector.empty())
	{
		cout << endl << "  Your cart is currently empty!" << endl;
		return;
	}
  
	cout << endl << "  You currently have " << cartVector.size() << " item(s) in your cart." << endl;
  
	cout << endl
		 << "     Quantity            Description            Price" << endl
		 << "    ---------- ------------------------------- -------" << endl;
                             
	for (vector<SaleItem*>::iterator it = cartVector.begin(); it != cartVector.end(); it++)
	{
		cout << left << setw(8) << setfill(' ') << "";
		cout << left << setw(7) << setfill(' ') << "1";
		cout << left << setw(32) << setfill(' ') << (*it)->getName();
		cout << right << setw(6) << setfill(' ') << setiosflags(ios::fixed) << setprecision(2) << (*it)->getPrice();
		cout << endl;
	}

	cout << endl;	
}

void ShoppingCart::checkout()
{
	cout << endl
		 << "  Your total is: " << setiosflags(ios::fixed) << setprecision(2) << calculateTotal() << endl
		 << "  Thank you for shopping with us today!" << endl;	
}
