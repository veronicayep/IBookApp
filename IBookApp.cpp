//This file contains the implementation code for the IBookApp class data member functions 
#include "IBookApp.h"

void IBookApp::run()
{
	int option = 0;
	while (option != CHECKOUT)
	{
		option = printMenuOptions();
		switch (option)
		{
			case VIEW_CATALOG:
				sortOption();
				mCatalog.printCatalog();
				printViewCatalogOptions();
				break;
			case VIEW_CART:
				mCart.printViewCart();
				break;
			case CHECKOUT:
				mCart.checkout();
			break;
		}
	}
}

int IBookApp::printMenuOptions()
{
	cout << endl
		 << "Welcome to IBookApp" << endl
		 << "  0. Browse the catalog" << endl
		 << "  1. View my shopping cart" << endl
		 << "  2. Checkout / Exit" << endl
		 << "Please choose an option: ";
	int option;
	cin >> option;
	if (cin && option >= 0 && option <= 2) //check the type of the input
	{
		return option;
	}
	cin.clear(); //clears the error flag
	cin.ignore(100, '\n'); //skips to the next line, ignore any input up to 100 characters
	cerr << endl << "ERROR: Sorry, that is an invalid option" << endl; //error stream
	return -1;
}

void IBookApp::printViewCatalogOptions()
{
	int response;
	cout << endl 
		 << "Would you like to" << endl
		 << "  0. Go back to main menu" << endl
     	 << "  1. Get more information about a product" << endl
    	 << "  2. Add an item to my shopping cart?" << endl
    	 << "Enter 0, 1 or 2: ";
	cin >> response;
	int productID;
	if (response == MORE_INFO)
	{
		cout << endl
			 << "Which product would like to know more about?" << endl
			 << "Product ID: ";
    cin >> productID;
    mCatalog.getProductInfo(productID);
    	cout << endl 
    		 << "Would you like to add this item to my shopping cart?" << endl
    		 << "Enter (y) for YES and (n) for NO: ";
    
		string addItemToCart;
    	cin >> addItemToCart;
    	if(addItemToCart == "y"||"Y"||"yes"||"Yes"||"YES")
    	{
    		SaleItem* item = mCatalog.getProduct(productID);
    		mCart.addItem(item);
		}
		else if (addItemToCart == "n"||"N"||"no"||"NO")
    	{
    		printViewCatalogOptions();
		}
	}
	else if (response == ADD_ITEM)
	{
    cout << endl
         << "Enter the ID of the product you would like to buy" << endl
         << "Product ID: ";
    cin.ignore();
    cin >> productID;
    SaleItem* item = mCatalog.getProduct(productID);
    mCart.addItem(item);
	}
}

void IBookApp::sortOption()
{
	int option;
	cout<< endl
		<< "Would you like to " <<endl
		<< " 0. Sort by Title" <<endl
		<< " 1. Sort by Price" <<endl
		<<"Enter 0 or 1: ";
	cin>> option;

while(option!= SORT_BY_TITLE &&option !=SORT_BY_PRICE)
{
	cout<< "Error, invalid input. Please enter 0 or 1: ";
	cin	>> option;

}
	if (option == SORT_BY_TITLE)
	{
		mCatalog.sortProductsByTitle();
	}
	else if (option == SORT_BY_PRICE)
	{
		mCatalog.sortProductsByPrice();
	}
}
