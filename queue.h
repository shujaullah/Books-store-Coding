/*
 * Name: SHUJAULLAH AHSAN
 * FINAL PROJECT.
 * Queue Member Function Definitions
 * Course: CSI218 (Spring 2019)
 * Date:May 15, 2019
 * Description: Queue member function definitions.
 *				Implementation using dynamic array.
 */
#ifndef QUEUE_H
#define QUEUE_H

template<class T>
class Queue
{
public:
	// Constructors
	Queue(int size);  // initial capacity

					  // Copy constructor
	Queue(const Queue<T> &otherQueue);

	// Assignment operator
	Queue<T> &operator =(
		const Queue<T> &otherQueue);

	// Destructor
	~Queue();

	// Determine emptiness or fullness
	bool isEmpty() const;
	bool isFull() const;

	// See value at front
	T front() const;

	// Add value to rear
	void add(const T &val);

	// Remove value at front
	void del();

private:
	T *elements;    // Point to dynamic array
	int capacity;   // Size of array
	int frontIndex; // Where front starts
	int numStored;  // Number values stored
};

#endif