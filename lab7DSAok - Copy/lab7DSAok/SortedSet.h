#pragma once
#include"SortedSetIterator.h"


typedef std::string TElem;

typedef TElem TComp;

class SortedSetIterator;

typedef bool(*Relation)(TComp, TComp);

struct BSTNode {
	TElem info;
	BSTNode* left;
	BSTNode* right;
};



class SortedSet {

	friend class SortedSetIterator;

private:

	/*Representation of the SortedSet*/
	BSTNode* root;
	Relation rel;
	int length;


public:

	//constructor

	SortedSet(Relation r);

	//adds an element to the sorted set

	//if the element was added, the operation returns true, otherwise (if the element was already in the set) 

	//it returns false

	bool add(TComp e);
	   	  
	//removes an element from the sorted set

	//if the element was removed, it returns true, otherwise false

	bool remove(TComp e);

	BSTNode* removeRecursively(BSTNode* node, TComp e, bool& removed);

	//checks if an element is in the sorted set



	bool search(TElem elem) const;





	//returns the number of elements from the sorted set

	int size() const;



	//checks if the sorted set is empty

	bool isEmpty() const;



	//returns an iterator for the sorted set

	SortedSetIterator iterator() const;



	// destructor

	~SortedSet();


	BSTNode* initNode(TElem e);

	BSTNode* minimum(BSTNode* node);

	BSTNode* parent(BSTNode* node);

	void empty();
};