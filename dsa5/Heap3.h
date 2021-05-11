#pragma once
#include "DynamicVector.h"

typedef int TElem;
typedef int TPriority;
typedef std::pair<TElem, TPriority> Element;
typedef bool(*Relation)(TPriority p1, TPriority p2);

class Heap3
{
private:
	DynamicVector<Element> elems{ 10 };
	Relation r;

	void sift(int vertex);
	void percolate(int vertex);
	int father(int vertex);

public:
	Heap3(Relation r);

	void add(Element elem);
	
	Element minim();

	void remove();

	bool isEmpty();
	~Heap3();
};

