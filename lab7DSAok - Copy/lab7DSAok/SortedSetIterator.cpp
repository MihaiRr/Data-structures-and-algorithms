#include<iostream>
#include"SortedSetIterator.h"

SortedSetIterator::SortedSetIterator(const SortedSet& set) : set(set) {
	//currentNode = nullptr;
	first();
}

void SortedSetIterator::next() {
	if (!valid()) throw std::exception();
	BSTNode* node;
	node = s.top();
	s.pop();
	if (node->right != nullptr) {
		node = node->right;
		while (node != nullptr) {
			s.push(node);
			node = node->left;
		}
	}
	if (!s.empty())
		this->currentNode = s.top();
	else
		this->currentNode = nullptr;
}

void SortedSetIterator::first() {
	while (!s.empty()) {
		s.pop();
	}
	BSTNode* node;
	node = set.root;
	while (node != nullptr) {
		s.push(node);
		node = node->left;
	}
	if (!s.empty())
		this->currentNode = s.top();
	else
		this->currentNode = nullptr;
}

bool SortedSetIterator::valid() const {
	if (set.isEmpty())
		return false;
	if (this->currentNode == nullptr)
		return false;
	else
		return true;
}

TElem SortedSetIterator::getCurrent() const {
	if (!valid()) throw std::exception();
	return this->currentNode->info;
}