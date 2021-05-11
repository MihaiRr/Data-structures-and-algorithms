#pragma once

#include "Set.h"

class Set;
typedef int TElem;

class SetIterator {
	friend class Set;
private:
	SetIterator(const Set& s);
	//contains a reference of the container it iterates over
	const Set& s;
	int currentIdx;
	int counter;
public:
	//sets the iterator to the first element of the container
	void first();

	//moves the iterator to the next element
	//throws exception if the iterator is not valid
	void next();

	//checks if the iterator is valid
	bool valid() const;

	//returns the value of the current element from the iterator
	// throws exception if the iterator is not valid
	TElem getCurrent() const;
};

