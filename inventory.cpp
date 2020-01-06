/*
 * Name: SHUJAULLAH AHSAN
 * FINAL PROJECT.
 * inventory class using link list
 * Course: CSI218 (Spring 2019)
 * Date:May 15, 2019
 * Description: link list which get the data of the sold and rent books
 *              and sort it with the ID using the templatre class
 */

#ifndef HISTORY_CPP
#define HISTORY_CPP

#include <iostream>
#include "inventory.h"
using namespace std;


template<class T>
Inventory<T>::Inventory()
{
	firstP = NULL;  // initially empty
	// ALSO INITIALIZE POINTER TO LAST NODE HERE.
	lastP = NULL;
}

template<class T>
Inventory<T>::Inventory(const Inventory<T>& otherInventory)
{
	firstP = NULL;  // initially empty
	// ALSO INITIALIZE POINTER TO LAST NODE HERE.
	lastP = NULL;

	// Copy list of other history.
	append(otherInventory);
}




// Destructor
template<class T>
Inventory<T>::~Inventory()
{
	clear();  // pointer reset once cleared
}

// Assignment operator
//template<class T>
//Inventory<T>& Inventory<T>:: operator =(
//	const Inventory<T>& otherInventory)
//{
//	// Avoid copying if assigning object to self.
//	if (this != &otherInventory)
//	{
//		// Copy non-dynamic array members (none here).
//
//		// Empty current list.
//		clear();
//
//		// Copy list of other history.
//		append(otherInventory);
//	}
//
//	// Return self.
//	return *this;
//}

// Accessors

// Precondition: "i" is zero-based index.
template<class T>
T Inventory<T>::get(int i) const
{
	int count = 0;

	for (Node<T>* traverseP = firstP;
		traverseP != NULL;
		traverseP = traverseP->linkP)
	{
		if (count == i)
			return traverseP->info;
		count++;
	}

	cerr << "Invalid history index: " << i << endl;
	return T();
}

template<class T>
void Inventory<T>::add(const T& val)
{
	// adding the new node in the end.

	// Allocate new node and store data.
	Node<T>* newNodeP = new Node<T>;
	newNodeP->info = val;
	newNodeP->linkP = NULL;

	if (firstP == NULL)
		firstP = newNodeP;
	else
		lastP->linkP = newNodeP;

	lastP = newNodeP;
}

// Remove all items
template<class T>
void Inventory<T>::clear()
{
	while (firstP != NULL)
	{
		Node<T>* deleteP = firstP;
		firstP = firstP->linkP;
		delete deleteP;
	}

	// After loop, firstP will be NULL.

	// ALSO SET RESET POINTER TO LAST NODE.
	lastP = NULL;
}

// Add all items from other history
template<class T>
void Inventory<T>::append(const Inventory<T> & otherInventory)
{
	for (Node<T>* traverseP = otherInventory.firstP;
		traverseP != NULL;
		traverseP = traverseP->linkP)
		add(traverseP->info);
}

// output the linlist objects.
template<class T>
void Inventory<T>::output() const
{
	cout << "Inventory";

	for (Node<T>* traverseP = firstP;
		traverseP != NULL;
		traverseP = traverseP->linkP)
		cout << " " <<traverseP->info << endl;
}
//the data stored in the link list so dont know the  length of the list
// and the link list will not give you the random access.
// so we need to divide the list into two sublists by using two pointers
//by finding the middle node of the link list..

// we traverse the list by two pointer middle and the current pointer
// middle initialized to the first node of the list and the current initailize 
// to the third node because sorting done on the link list if it has more then
// one elements.
// so when we move the middle pointer the current pointer moves one advanced.
// so if current is not equal to null it will advaced one node. So when the middle moves
// current moves 2  nodes.
// when the current equal to null the middle pointer will point the end of the first sublist.
// the parameter is passing the refefrence to node pointers first1 and first2.
template <class T>
void Inventory<T>::dividing(Node<T>* & first1,
	Node<T>*& first2)
{
	// declaring the two pointer for the mid and teh currentt node
	Node<T>* middle;
	Node<T>* current;
	if (first1 == NULL) //list is empty
		first2 = NULL;
	else if (first1->linkP == NULL) //list has only one node
		first2 = NULL;
	else
	{
		middle = first1;
		current = first1->linkP;
		if (current != NULL) //list has more than two nodes
			current = current->linkP;
		while (current != NULL)
		{
			middle = middle->linkP;
			current = current->linkP;
			if (current != NULL)
				current = current->linkP;
		} 
		//first2 points to the first
		first2 = middle->linkP; 
		//set the link of the last node
		//of the first sublist to NULL
		middle->linkP = NULL; 
		
	} 
}
// the merge sort function is to merge the sorted sublist 
// it take help of the new headPointer which points to the first sublist 
// and last small pointing to the last node of the merged lsit.
// merge the list with that using the it.
// the function help to merge the two divide link list.
template <class T>
Node<T>* Inventory<T>::
mergingList(Node<T>* first1,
	Node<T>* first2)
{
	Node<T>* lastSmall; //pointer to the last node of
	//the merged list
	//pointer to the merged list
	Node<T>* newHead; 
    //the first sublist is empty
	if (first1 == NULL)
		return first2;
	//the second sublist is empty
	else if (first2 == NULL) 
		return first1;
	else
	{
		//compare the first nodes
		if (first1->info < first2->info) 
		{
			newHead = first1;
			first1 = first1->linkP;
			lastSmall = newHead;
		}
		else
		{
			newHead = first2;
			first2 = first2->linkP;
			lastSmall = newHead;
		}
		while (first1 != NULL && first2 != NULL)
		{
			if (first1->info < first2->info)
			{
				lastSmall->linkP = first1;
				lastSmall = lastSmall->linkP;
				first1 = first1->linkP;
			}
			else
			{
				lastSmall->linkP = first2;
				lastSmall = lastSmall->linkP;
				first2 = first2->linkP;
			}
		} //end while
		if (first1 == NULL) //first sublist is exhausted first
			lastSmall->linkP = first2;
		else //second sublist is exhausted first
			lastSmall->linkP = first1;
		return newHead;
	}
}
// the recursive mergelist will help use the divide 
// and merging list function to  sort the list.
// it has the refernce to the first node of the list as a parameter.
template <class T>
void Inventory<T>::recMergeSort(Node<T>*& head)
{
	Node<T>* otherHead;
	//if the list is not empty
	if (head != NULL) 
		//if the list has more than one node
		if (head->linkP != NULL) 
		{
			// callling the functions 
			// recursion happening too.
			dividing(head, otherHead);
			recMergeSort(head);
			recMergeSort(otherHead);
			head = mergingList(head, otherHead);
		}
} 

// mergesort function just call the recursive merge sort function 
template<class T>
void Inventory<T>::mergeSort()
{
	recMergeSort(firstP);
	// special case.
	if (firstP == NULL)
		lastP = NULL;
	// else the lastP will assign to the firstP
	// it point to the linkP if its not null.
	else
	{
		lastP = firstP;
		while (lastP->linkP != NULL)
			lastP = lastP->linkP;
	}
}



#endif