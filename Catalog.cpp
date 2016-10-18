#include "Catalog.h"
#include "Book.h"
#include "Magazine.h"

#include <iostream>
#include <string>
#include <iomanip>


Catalog::Catalog()
{ 	//new operator to create books and magazines to fill the catalog vector with data -dynamic memory (object will be store on the heap)
	Book* book1 = new Book("The Lord of the Rings", 9.99, new Date(1, 1, 2016), "Book", 123456, "J. R. R. Tolkien", "George Allen & Unwin"); 
	Book* book2 = new Book("The Hobbit", 19.50, new Date(12, 12, 2005), "Book", 654321, "J. R. R. Tolkien", "George Allen & Unwin");
	Book* book3 = new Book("The Little Prince", 11.99, new Date(1, 1, 2016), "Book", 123456, "Antoine de Saint-Exupéry", "Reynal & Hitchcock");
	Book* book4 = new Book("And Then There Were None", 7.39, new Date(6, 11, 2011), "Book", 123456, "Agatha Christie", "Collins Crime Club");
	Book* book5 = new Book("The Thorn Birds", 8.90, new Date(1, 1, 2016), "Book", 123456, "Colleen McCullough", "Harper & Row");
	Book* book6 = new Book("The Da Vinci Code", 33.00, new Date(1, 1, 2016), "Book", 123456, "Dan Brown", "Doubleday");
	Book* book7 = new Book("The Alchemist", 24.99, new Date(1, 1, 2016), "Book", 123456, "Paulo Coelho", "George Allen & Unwin");
	Book* book8 = new Book("One Hundred Years of Solitude", 28.09, new Date(1, 1, 2016), "Book", 123456, "Gabriel García Márquez", "Harper & Row");
	Book* book9 = new Book("Charlotte's Web", 10.95, new Date(1, 1, 2016), "Book", 123456, "E.B. White", "Doubleday");
	Book* book10 = new Book("The Diary of a Young Girl", 20.99, new Date(1, 1, 2016), "Book", 123456, "Anne Frank", "Jonathan Cape");
	catalogVector.push_back(book1);
	catalogVector.push_back(book2);
	catalogVector.push_back(book3);
	catalogVector.push_back(book4);
	catalogVector.push_back(book5);
	catalogVector.push_back(book6);
	catalogVector.push_back(book7);
	catalogVector.push_back(book8);
	catalogVector.push_back(book9);
	catalogVector.push_back(book10);
  
	Magazine* mag1 = new Magazine("Attitude", 100.66, new Date(5, 1, 2016), "Magazine", "Media", 1);
	Magazine* mag2 = new Magazine("Candis", 92.76, new Date(4, 2, 2016), "Magazine", "Newhall Publishing Ltd", 2);
	Magazine* mag3 = new Magazine("Dorset", 61.97, new Date(5, 1, 2016), "Magazine", "Archant Life", 1);
	Magazine* mag4 = new Magazine("LandLove", 97.56, new Date(4, 2, 2016), "Magazine", "Hubert Burda Media Uk", 2);
	Magazine* mag5 = new Magazine("Psychologies Travel Size", 97.56, new Date(5, 1, 2016), "Magazine", "Kelsey", 1);
	Magazine* mag6 = new Magazine("Prima", 83.60, new Date(4, 2, 2016), "Magazine", "Hearst Magazines", 2);
	Magazine* mag7 = new Magazine("Soul & Spirit", 120.34, new Date(5, 1, 2016), "Magazine", "Aceville Publications Ltd Dovetail", 1);
	Magazine* mag8 = new Magazine("Skin Deep", 92.92, new Date(4, 2, 2016), "Magazine", "Jazz Publishing", 2);
	Magazine* mag9 = new Magazine("Scottish Woman", 54.23, new Date(5, 1, 2016), "Magazine", "Scottish Woman Magazine", 1);
	Magazine* mag10 = new Magazine("Yorkshire Women's Life", 39.02, new Date(4, 2, 2016), "Magazine", "Yorkshire Womens Life", 2);
	catalogVector.push_back(mag1);
	catalogVector.push_back(mag2);
	catalogVector.push_back(mag3);
	catalogVector.push_back(mag4);
	catalogVector.push_back(mag5);
	catalogVector.push_back(mag6);
	catalogVector.push_back(mag7);
	catalogVector.push_back(mag8);
	catalogVector.push_back(mag9);
	catalogVector.push_back(mag10);
}

void Catalog::printCatalog()
{
	if (catalogVector.empty())
	{
		cout << "The catalog is empty!" << endl;
		return;
	}
	
  
	cout << endl
    	 << "     Product ID   Category            Description            Price" << endl
    	 << "    ------------ ---------- ------------------------------- -------" << endl;

	for (vector<SaleItem*>::iterator it = catalogVector.begin(); it != catalogVector.end(); it++)
	{
		cout << left << setw(9) << setfill(' ') << "";
		cout << left << setw(8) << setfill(' ') << (*it)->getProductID();
		cout << left << setw(11) << setfill(' ') << (*it)->getCategory();
		cout << left << setw(33) << setfill(' ') << (*it)->getName();
		cout << right << setw(6) << setfill(' ') << setiosflags(ios::fixed) << setprecision(2) << (*it)->getPrice();
		cout << endl;
	}

	cout << endl;
	
	
}

void Catalog::getProductInfo(const int productID)
{
	cout << endl << "Details about the item:" << endl;
	cout <<	*getProduct(productID) << endl;
}

SaleItem* Catalog::getProduct(const int productID)
{
	
	for (vector<SaleItem*>::iterator it = catalogVector.begin(); it != catalogVector.end(); it++){
	if((*it)->getProductID() == productID)
		{
			return (*it);
		}
	}
	return NULL;
	
}

bool compareByTitle(SaleItem* book1, SaleItem* book2)
{
	return book1->getName() < book2->getName();
}
bool compareByPrice(SaleItem* book1, SaleItem* book2)
{
	return book1->getPrice() < book2->getPrice();
}

void Catalog::sortProductsByTitle()
{
	sort(catalogVector.begin(),catalogVector.end(),compareByTitle);
}
void Catalog::sortProductsByPrice()
{
	sort(catalogVector.begin(),catalogVector.end(),compareByPrice);
}
