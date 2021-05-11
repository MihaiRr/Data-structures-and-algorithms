#include<iostream>
#include"SortedSet.h"

SortedSet::SortedSet(Relation r) {
	this->root = new BSTNode;
	this->root = nullptr;
	this->rel = r;
	this->length = 0;
}

//complexity: O(n)
bool SortedSet::add(TComp e) {
	if (search(e))
		return false;
	bool added = false;
	BSTNode* currentNode;
	BSTNode* node;
	currentNode = this->root;
	if (currentNode == nullptr) {
		node = initNode(e);
		this->root = node;
		this->length++;
		return true;
	}
	while (!added && currentNode != nullptr) {
		if (!rel(currentNode->info, e)) {
			if (currentNode->left == nullptr) {
				node = initNode(e);
				currentNode->left = node;
				added = true;
				this->length += 1;
				return true;
			}
			else
				currentNode = currentNode->left;
		}
		else {
			if (currentNode->right == nullptr) {
				node = initNode(e);
				currentNode->right = node;
				added = true;
				this->length += 1;
				return true;
			}
			else
				currentNode = currentNode->right;
		}
	}
}


//complexity: O(n)
bool SortedSet::remove(TComp e) {
	BSTNode* currentNode;
	currentNode = this->root;
	BSTNode* node{};
	BSTNode* minNode;
	BSTNode* p;
	BSTNode* child;
	bool found = false;
	if (!search(e))
		return false;
	while (currentNode != nullptr and !found) {
		if (currentNode->info == e) {
			node = currentNode;
			found = true;
		}
		else if (rel(currentNode->info, e))
			currentNode = currentNode->right;
		else
			currentNode = currentNode->left;
	}
	if (node == this->root) {
		if (this->root->left == nullptr and this->root->right == nullptr) {
			this->length--;
			root = nullptr;
			return true;
		}
		else {
			if (this->root->right != nullptr) {
				this->root = this->root->right;
				this->length--;
				return true;
			}
			else {
				this->root = this->root->left;
				this->length--;
				return true;
			}
		}
	}
	if (node->left != nullptr and node->right != nullptr) {
		minNode = minimum(node->right);
		node->info = minNode->info;
		p = parent(minNode);
		p->left = nullptr;
		this->length--;
		delete node;
		return true;
	}
	else if (node->left == nullptr and node->right == nullptr) {
		p = parent(node);
		if (p->left == node)
			p->left = nullptr;
		else
			p->right = nullptr;
		this->length--;
		delete node;
		return true;
	}
	else if (node->left == nullptr or node->right == nullptr) {
		if (node->left != nullptr)
			child = node->left;
		else
			child = node->right;
		p = parent(node);
		if (p->left == node)
			p->left = child;
		else
			p->right = child;
		this->length--;
		delete node;
		return true;
	}
	return false;
}


//complexity: O(n)
bool SortedSet::search(TElem e) const {
	if (this->length == 0 || this->root == nullptr)
		return false;
	BSTNode* currentNode;
	currentNode = this->root;
	bool found = false;
	while (currentNode != nullptr and !found) {
		if (currentNode->info == e)
			found = true;
		else if (rel(currentNode->info, e))
			currentNode = currentNode->right;
		else
			currentNode = currentNode->left;
	}

	return found;

}

int SortedSet::size() const {
	return length;
}

bool SortedSet::isEmpty() const {
	return length == 0;
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}

SortedSet::~SortedSet() {
	//delete root;
}

BSTNode* SortedSet::initNode(TElem e)
{
	BSTNode* node = new BSTNode;
	node->info = e;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}


//complexity: O(n)
BSTNode* SortedSet::minimum(BSTNode* node)
{
	BSTNode* currentNode = new BSTNode;
	currentNode->info = node->info;
	currentNode->left = node->left;
	currentNode->right = node->right;
	if (currentNode == nullptr)
		return nullptr;
	else
		while (currentNode->left != nullptr)
			currentNode = currentNode->left;
	return currentNode;
}


//complexity: O(n)
BSTNode* SortedSet::parent(BSTNode* node)
{
	BSTNode* c;
	c = this->root;
	if (c->info == node->info)
		return nullptr;
	else {
		while (c != nullptr and c->left != node and c->right != node)
			if (!rel(c->info, node->info))
				c = c->left;
			else
				c = c->right;
		return c;
	}
}

void SortedSet::empty()
{
	TComp e;
	SortedSetIterator it = this->iterator();
	it.first();
	e = it.getCurrent();
	while (it.valid())
	{
		this->remove(e);
		it.next();
		e = it.getCurrent();
	}
}
