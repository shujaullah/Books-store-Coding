/*
* Name: ShujaUllah Ahsan
* FINAL PROJECT
* AHSAN'S BOOKSTORE
* Course : CSI218(Spring 2019)
* 
* Date : May 15, 2019
* Description : Using template class containing linked list
*keeping track of the books by id using the link list. 
* the vector in the main also store the customers information.
* The book  store has the best seller or you also search the book of desire by ID
* and rent or buy it.
*best seller book its a que for it.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>  // for stringstream
#include <algorithm>
#include <cstdlib>  // for rand()
#include "book.h"
#include"inventory.cpp"
//#include "priceHistory.cpp";
#include <vector>
#include "queue.cpp"
#include<stack>
#include <ctime>
#include<vector>
using namespace std;

// temoplate function for the linear search
template<class T>
int findLinear(T elements[],
	int numElements,
	const T& searchElement);
int main()
{
	srand((signed) time(NULL));
	// conmstants for the id of the books and the max price.
	const string  ID_NUMBER = "217-675-34-";
	const double MAX_PRICE = 400.0;


	int numBooks = 5;
	// declaring the dynamic array for the book from book class
	// similar for the que of the best seller books queue class
	Book *books = new Book[numBooks];
	Queue<string> custQueue(5);

	// the book store just have the one best seller book
	Book* bestSeller = new Book[1];
	Inventory<string>  bookRental;
	Inventory<string> soldBooks;
	
	// string arrray for the for the name of the books and author put in the book array
	string bookName[] = { "Advanced Cplus plus","Java for the beginers",
		"Intro to computers", "Database Management" };
	string authorLastName[] = { "Carol", "Yip", "Lee", "Barthelemy" };

	// using the vector with the pairing  and name it with the names.
	vector < pair<string, string> > names;
	//push back the vector for the values of the  names of book and the author.
	for (int i = 0; i<4; i++)
		names.push_back(make_pair(bookName[i], authorLastName[i]));

	for (int i = 0; i < numBooks; i++)
	{
		// using the random shuffle function from alogrithm klibrary for the vector to shuflle the 
		// name of the booksand author.
		random_shuffle(names.begin(), names.end());

		// random genetaror for the ids of the book
		int id = rand() % 100;
		// concatenate the strings and using the to string function randomely generated
		string idNumber = ID_NUMBER + to_string (id);
		//randomely generated the prices of the book.
		double price = (rand() /(double) RAND_MAX * MAX_PRICE);
		int numCopies = rand() % 5 + 1;
		//random_shuffle(names.begin(), names.end());
		//randomely genartin the number for the books and author and pass it to the
		// set function accordingly.
		int bookName = rand() % 4;
		int authorName = rand() % 4;
		books[i].set(names[bookName].first, idNumber , price, numCopies, names[authorName].second);

		 

	}
	//setting the best seller book of the store with name price and the id 

	bestSeller[0].set("Advaced Java", "213-345-45-33", 600.00, 5, "Francis");
	const int NUM_BOOKS = 5;
	char answer;

	cout << "Welcome To The Ahsan's Book Store" << endl;

	cout << "----------------------------------" << endl;
	
	cout << "The variety of he books in the book store" << endl;
	cout << "___________________________________________" << endl;


	for (int i = 0; i < numBooks; i++)
	{
		books[i].output();
	}

	// do while loop will run for the search the books in the store once disapalyed by the above loop.
	// the do wile loop also put the books sold and the rent into the link list
	// and sort the list so duing the inventory of the store we should know waht books we needed.
	do
	{
		string id;
		cout << "\nFind book with id (Enter to exit): ";
		getline(cin, id);  // read whole line

		if (id == "")
			break;

		// CHANGE TO USE GENERIC SEARCHING FUNCTION.
		Book searchBooks("cplus plus", id, 10.0, "yip", 5);

		//Book searchBooks(names[check].first, id, 10.0, "pitts", 1);

		int index = findLinear(books, numBooks, searchBooks);
		//int index = findBinary(products, numProducts, searchProduct);
		//Product *foundP = find(products, products + numProducts, searchProduct);
		//int index = findBinaryRecursive(products, 0, numProducts - 1, searchProduct);




		if (index == -1)
			//if (foundP == products + numProducts)
			cout << "No product with id \"" << id << "\"" << endl;
		else
		{
			cout << "Found product:" << endl;
			books[index].output();
			//foundP->output();
			cout << endl << endl;
			cout << "You want to rent  or buy (r/b): ";
			char choice;
			cin >> choice;
			string empty;
			getline(cin,empty);
			if (choice == 'r' || choice == 'R')
			{
				// renting book price of 25 percent of the price.
				double rentPrice = books[index].getPrice() * 0.25;
				cout << "The price of the book is now :" << rentPrice << endl;
				bookRental.add(books[index].getId());
				int decNumCopies = books[index].getNumCopies() - 1;
				books[index].setNumCopies(decNumCopies);
			}
			else if (choice == 'b' || choice == 'B')
			{
				cout << "The price of the book is" << books[index].getPrice() << endl;

				soldBooks.add(books[index].getId());

				int decNumCopies = books[index].getNumCopies() - 1;
				//books[index].setNumCopies(decNumCopies);
			}
			else
				cout << "you enter in valid syntax" << endl;

		}

	} while (true);

	//declaring the stuct for th customer information
	struct customerInfo
	{
		string name;
		string address;

	};
	// the vector will keep the tratclk of the customer purcahsing the best seller book
	// if the book sold out in the store we still mail them to the their home.
	vector<customerInfo> customerList;
	cout << "Would you like to buy best seller book advanced java by francis (y/n): ";
	cin >> answer;
	if (answer == 'y' || answer == 'Y')
	{
		customerInfo information;
		int custNum = 1;
		int maxCustomer = 5;
		//while (!custQueue.isFull() && custNum <= maxCustomer)
		if(!custQueue.isFull())
		{
			string name, address;
			cout << "\nEnter customer #" << custNum << " name: ";
			getline(cin, name);
			string empty;
			getline(cin, empty);
			cout << "Please enter your address:";
			cin >> address;
			cout << "Sending customer \"" << name
				<< "\" to end of line" << endl;

			custQueue.add(name);
			custNum++;

			information.name = name;
			information.address = address;
			customerList.push_back(information);
		}
		

		int bookSold = 0;
		cout << "You are in a que wait for the distribution" << endl;

		cout << "\nPress Enter to distribute "
			<< NUM_BOOKS << " in stock copies "
			<< "of the best seller";
		cin.get();  // read newline

		cout << fixed << setprecision(2);  // 2 decimal places

		while (!custQueue.isEmpty())
		{
			int i = 0;
			string name = custQueue.front();  // see who on front
			cout << "\nServing customer \"" << name << "\":" << endl;

			if (bookSold >= NUM_BOOKS)
			{
				cout << "Sorry we sold out of the book advanced java by Francis"
					<< "We will mail you the book with free shiping in 2 days" << endl;
				break;
			}

			custQueue.del(); // actually remove from queue

			cout << "Please pay: $" << bestSeller[i].getPrice() << "on the counter. "<< endl;
			bookSold++;
			i++;
		}

		cout << "\nAll customers received our best seller: "
			<< boolalpha << custQueue.isEmpty()
			<< endl << endl;
	}
	else
		cout << "Enjoying business with you" << endl;
	
	/*Inventory<string> checkSort;
	for (int i = 0; i < numBooks; i++)
	{
		checkSort.add(books[i].getId());
	}
	checkSort.mergeSort()
	checkSort.output();
	
*/
	//sorting the linlisty of the sold books and the rent books
	// also outputing them in the end;
	bookRental.mergeSort();
	soldBooks.mergeSort();
	bookRental.output();
	cout << " " << endl;
	soldBooks.output();

	// dealloacting the dynamic array.
	delete [] books;
	books = NULL;

	return 0;




}

// defination of the linear search template function.
template<class T>
int findLinear(T elements[],
	int numElements,
	const T& searchElement)
{
	for (int i = 0; i < numElements; i++)
		if (elements[i] == searchElement)
			return i;
	return -1;
}