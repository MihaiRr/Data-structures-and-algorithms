#include <iostream>
#include "Set.h"

Set::Set() :_size{ 0 }, ht{} {
	ht.m = 10;
	ht.elems = new Node[ht.m]();
	ht.firstFree = -1;
	for (int i = 0; i < ht.m; i++) {
		ht.elems[i].next = EMPTY_ELEM;
		ht.elems[i].info = EMPTY_ELEM;
	}
}
//WC=AC=Theta(n), => overall complexity = theta(n), where n = capacity
//BC=Theta(1)
void HashTable::changeFirstFree() {
	for (firstFree = firstFree + 1; firstFree < m && elems[firstFree].info != EMPTY_ELEM; firstFree++)
		;
}

//WC=AC=BC=Theta(n), => overall complexity = theta(n), where n = capacity
void HashTable::resize() {
	int oldM = m;
	m *= 2;
	auto newElems = new Node[m];
	for (int i = 0; i < m; i++) {
		newElems[i].next = EMPTY_ELEM;
		newElems[i].info = EMPTY_ELEM;
	}
	firstFree = -1;
	for (int i = 0; i < oldM; i++) {
		int newPos = abs(elems[i].info % m);
		if (newElems[newPos].info == EMPTY_ELEM) {
			newElems[newPos].info = elems[i].info;
			newElems[newPos].next = EMPTY_ELEM;
		}
		else {
			for (firstFree = firstFree + 1; firstFree < m && newElems[firstFree].info != EMPTY_ELEM; firstFree++)
				;
			int current = newPos;
			while (newElems[current].next != EMPTY_ELEM)
				current = newElems[current].next;
			newElems[current].next = firstFree;
			newElems[firstFree].info = elems[i].info;
		}
	}
	delete[] elems;
	elems = newElems;
}
//WC=AC=Theta(n), => overall complexity = theta(n), where n = capacity
//BC=Theta(1), if the element already exist in the array or if we add it on the hash position
bool Set::add(TElem e) {
	if (search(e))
		return false;
	if (_size == ht.m) {
		ht.resize();
	}
	int pos = abs(e % ht.m);
	if (ht.elems[pos].info == EMPTY_ELEM) {
		ht.elems[pos].info = e;
		ht.elems[pos].next = EMPTY_ELEM;
	}
	else {
		ht.changeFirstFree();
		int current = pos;
		while (ht.elems[current].next != EMPTY_ELEM)
			current = ht.elems[current].next;
		ht.elems[current].next = ht.firstFree;
		ht.elems[ht.firstFree].info = e;
		ht.elems[ht.firstFree].next = EMPTY_ELEM;
	}
	_size++;
	return true;
}


//WC=AC=Theta(n), => overall complexity = theta(n), where n = capacity
//BC=Theta(1), if the element does not exist in the array or if we delete the elem from the first pos
bool Set::remove(TElem e) {
	if (!search(e))
		return false;
	int pos = abs(e % ht.m);
	int prev = EMPTY_ELEM;
	while (ht.elems[pos].next != EMPTY_ELEM and ht.elems[pos].info != e) {
		prev = pos;
		pos = ht.elems[pos].next;
	}
	if (ht.elems[pos].info == e) {
		if (prev != EMPTY_ELEM) {
			ht.elems[prev].next = ht.elems[pos].next;
		}
		else {
			if (ht.elems[pos].next != EMPTY_ELEM) {
				int nextElem = ht.elems[pos].next;
				ht.elems[pos].info = ht.elems[nextElem].info;
				ht.elems[pos].next = ht.elems[nextElem].next;
				pos = nextElem;
			}
		}
		ht.elems[pos].info = EMPTY_ELEM;
		ht.elems[pos].next = EMPTY_ELEM;
		if (pos < ht.firstFree)
			ht.firstFree = pos - 1;
		_size--;
		return true;
	}
	else {
		for (int i = 0; i < ht.m; i++) {
			if (ht.elems[i].info == e) {
				ht.elems[i].info = EMPTY_ELEM;
				ht.elems[i].next = EMPTY_ELEM;
				if (i < ht.firstFree)
					ht.firstFree = i - 1;
				break;
			}
		}
		_size--;
		return true;
	}
}



//WC=AC=Theta(n), => overall complexity = theta(n), where n = capacity
//BC=Theta(1), when the searched elem is in on the first pos
bool Set::search(TElem elem) const {

	for (int i = 0; i < ht.m; i++) {
		if (ht.elems[i].info == elem) {
			return true;
		}
	}
	return false;
}

//WC=AC=BC=Theta(1) => overall complexity = theta(1)
int Set::size() const {
	return _size;
}

//WC=AC=BC=Theta(1) => overall complexity = theta(1)
bool Set::isEmpty() const {
	return _size == 0;
}

SetIterator Set::iterator() const {
	return SetIterator{ *this };
}

//WC=AC=BC=Theta(1) => overall complexity = theta(1)
Set::~Set() {
	delete[] ht.elems;
}


