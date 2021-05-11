#pragma once
#include "SortedSet.h"
#include<stack>
#include<iostream>
using namespace std;

//complexity of inorder traversal with stack: time: theta(n), extra space: O(n)

typedef std::string TElem;

struct BSTNode;

class SortedSet;

class SortedSetIterator {

	friend class SortedSet;

public:

	const SortedSet& set;
	BSTNode* currentNode;
	stack <BSTNode*> s;

private:
	SortedSetIterator(const SortedSet& set);
public:

	bool valid() const;

	TElem getCurrent() const;

	void first();

	void next();

	~SortedSetIterator() {
	}

};