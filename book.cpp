/*
* Name: ShujaUllah Ahsan
* FINAL PROJECT
* AHSAN'S BOOKSTORE
* Course : CSI218(Spring 2019)
*
* Date : May 15, 2019
* Description : Book class for creating the book object
* having the name, ID, Author name , price.
*/
#include <iostream>
#include <iomanip>  // for setprecision()
#include "book.h"
using namespace std;

const int NUM_OF_COPY = 5;
Book::Book()
{
	name = "no name";
	id = "216-457-98-";

	price = 0.0;
	numCopies = 0;

	auLastName = "";
	//taxable = false;

}
// constructor for the book classs.

Book::Book(const string &newName, const string &newId,  double newPrice, const string &newauLastName,int newNumCopies)
{
	set(newName,newId, newPrice, newNumCopies, newauLastName);
	/*name = newName;
	auLastName = newauLastName;*/
}

// set function for the price etc.
void Book::set(string newName,string newId, double newPrice,int newNumCopies, string  newAulastNAme)
{
	name = newName;
	auLastName = newAulastNAme;
	id = newId;
	setPrice(newPrice);
	setNumCopies(newNumCopies);
	//taxable = newTaxable;


}
//acccesor

string Book::getId() const
{
	return id;
}

double Book::getPrice() const
{
	return price;
}

int Book::getNumCopies() const
{
	return numCopies;
}

string Book::getId()
{
	return id;
}

void Book::decreaseNumCopies()
{
	numCopies--;
}

// function for the printing the object.
void Book::output()
{
	cout << "Book name " << name
		<< "\nAuthor last name " << auLastName
		<< "\nId: " << id 
		<< "\nPrice: $"
		<< fixed << setprecision(2)
		<< price <<
		"\nNumber of copies " << numCopies << "\n"<<endl;



}

//int decreaseNumCopies(int number)
//{
//
//	//numCopies = numcopies - number;
//	if (== 0)
//		cout << "we sold of the book\n";
//	numCopies = numCopies - number;
//}

void Book::setPrice(double newPrice)
{
	if (newPrice < 0.0)
		cerr << "Invalid price";
	price = newPrice;

}
void Book::setNumCopies(int newNumCopies)
{
	if (newNumCopies <= NUM_OF_COPY)
		numCopies = newNumCopies;
	else
	{
		numCopies = 0;
		cerr << "We are not allowed to have that much of copy in the store" << endl;
	}
}

// operator overloading for the searching operation

bool operator ==(const Book& prod1,
	const Book& prod2)
{
	return prod1.getId() == prod2.getId();
}


bool operator <(const Book& prod1,
	const Book& prod2)
{
	return prod1.getId() < prod2.getId();
}
