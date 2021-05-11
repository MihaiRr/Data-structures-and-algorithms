#pragma once
#include "MultiMap.h"

class MultiMap;

class MultiMapIterator
{
	friend class MultiMap;

private:
	const MultiMap& mm;
	int counter;
	int currentElement;
	VNode* currentNode;
	MultiMapIterator(const MultiMap& mm);

public:
	TElemIterator getCurrent()const;
	bool valid() const;
	void next();
	void first();
};

