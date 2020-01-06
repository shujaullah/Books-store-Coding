/*
 * Name: SHUJAULLAH AHSAN
 * FINAL PROJECT.
 * inventory class using link list
 * Course: CSI218 (Spring 2019)
 * Date:May 15, 2019
 * Description: link list which get the data of the sold and rent books
 *              and sort it with the ID using the templatre class
 */

// using thereference of the book page number 560-566

#ifndef HISTORY_H
#define HISTORY_H

// declaring the struct node for the link list
template<class T>
struct Node
{
	T info;
	Node<T>* linkP;
};

template<class T>
class Inventory 
{

public:

	// constructor.
	Inventory();

	// Copy constructor
	Inventory(const Inventory<T>& otherInventory);

	// Assignment operator
	/*Inventory<T>& operator =(
		const InventoryT>& otherInventory);*/

	// Destructor
	~Inventory();

	// Accessors

	T get(int i) const;
	// Precondition: "i" is zero-based index.

	void output() const;

	// Mutators

	void add(const T& val);

	void clear();

	
	// mergesort will call in the main with object name will helpto 
	// automaticaly sort the  link list objects.
	void mergeSort();

private:
	Node<T>* firstP;  // point to first node (head) of linked list
	Node<T>* lastP; // point last node  of the link list.
	// Append items to end of history (make
	// this "public" if useful to "client").
	void append(const Inventory<T>& otherInventory);
	// function to divide the link list 
	void dividing(Node<T>* &first1, Node<T>*& first2);
	// merging the two list together
	Node<T>* mergingList(Node<T>* first1, Node<T>* first2);

	// recursive merge function will call the divide and mergig the list function
	// do divide and combine the list.
	void recMergeSort(Node<T>*& head);
	

};










#endif
