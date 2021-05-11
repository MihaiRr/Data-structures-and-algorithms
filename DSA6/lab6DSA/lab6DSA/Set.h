#pragma once

#define EMPTY_ELEM 99999

#include "SetIterator.h"
#include <cmath>

class SetIterator;
typedef int TElem;

struct Node {
	TElem   info;
	int     next;
};

struct HashTable {
	Node    *elems;
	int     m;
	int     firstFree;
	void    changeFirstFree();
	void    resize();
};

class Set {
	friend class SetIterator;
public:
	HashTable   ht;
	int         _size;

public:
	//implicit constructor
	Set();

	//adds an element to the  set
	//if the element was added, the operation returns true, otherwise (if the element was already in the set)
	//it returns false
	bool add(TElem e);

	//removes an element from the set
	//if the element was removed, it returns true, otherwise false
	bool remove(TElem e);

	//checks if an element is in the  set
	bool search(TElem elem) const;

	//returns the number of elements;
	int size() const;

	//checks if the set is empty
	bool isEmpty() const;

	//returns an iterator for the set
	SetIterator iterator() const;

	//destructor
	~Set();

	
};











