#include <stdexcept>
#include "SetIterator.h"
#include <iostream>
SetIterator::SetIterator(const Set &s) :s{ s }, currentIdx{ 0 }, counter{ 0 } {
	for (currentIdx = 0; currentIdx < s.ht.m && s.ht.elems[currentIdx].info == EMPTY_ELEM; currentIdx++)
		;
}
//WC = AC = Theta(n) = > overall complexity = theta(1)
//BC = Theta(1)
void SetIterator::next() {
	if (!valid())
		throw std::runtime_error("Iterator not valid");
	counter++;
	for (currentIdx = currentIdx + 1; currentIdx < s.ht.m && s.ht.elems[currentIdx].info == EMPTY_ELEM; currentIdx++)
		;
}

//WC=AC=BC=Theta(1) => overall complexity = theta(1)
bool SetIterator::valid() const {
	return counter < s._size;
}

//WC = AC = BC = Theta(1) = > overall complexity = theta(1)
TElem SetIterator::getCurrent() const {
	if (!valid())
		throw std::runtime_error("Iterator not valid");
	return s.ht.elems[currentIdx].info;
}

//WC = AC = Theta(n) = > overall complexity = theta(1)
//BC = Theta(1)
void SetIterator::first() {
	counter = 0;
	for (currentIdx = 0; currentIdx < s.ht.m && s.ht.elems[currentIdx].info == EMPTY_ELEM; currentIdx++)
		;
}