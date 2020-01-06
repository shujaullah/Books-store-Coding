
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
#ifndef BOOKS_H
#define BOOKS_H

#include <string>
using namespace std;
class Book
{
public:
	//constructors
	Book();

	Book(const string& newName, const string& newId, double newPrice, const string& newauLastName, int newNumCopies);

	/*Book(string newName, string newId, double newPrice, string newaulastName, int newNumCopies);*/

	//accesors
	string getId() const;

	//string getName() const;

	double getPrice() const;
	int getNumCopies()const;
	string getId();
	void decreaseNumCopies();
	//outPut
	void output();
	//mutators
	void set(string newName, string newId, double newPrice, int newNumCopies, string  newAulastNAme);

	void setPrice(double newPrice);
	void setNumCopies(int newNumCopies);
	

private:
	string name;
	string id;

	double price;
	string auLastName;
	//bool taxable;

	int numCopies;

};

//overloading operators precondition
bool operator ==(const Book& prod1,
	const Book& prod2);
// Postcondition: Compare as equal if have same id.

// Less than operator so that products can be compared.
bool operator <(const Book& prod1,
	const Book& prod2);
// Postcondition: Compare as less than if id of first is
// less than id of second.

#endif