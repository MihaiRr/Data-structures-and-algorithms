#pragma once
#include <utility>
#include "Heap3.h"

typedef int TElem;

typedef int TPriority;



typedef std::pair<TElem, TPriority> Element;



typedef bool(*Relation)(TPriority p1, TPriority p2);



class PriorityQueue {

private:
	Heap3 heap;



public:

	//implicit constructor

	PriorityQueue(Relation r) : heap{ r } {}



	//adds an element with priority to the queue

	void push(TElem e, TPriority p);



	//returns the element with the highest priority with respect to the order relation

	//throws exception if the queue is empty

	Element top();



	//removes and returns the element with the highest priority

	//throws exception if the queue is empty

	Element pop();



	//checks if the queue is empty

	bool isEmpty();



	//destructor

	~PriorityQueue();



};