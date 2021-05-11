#include "MultiMapIterator.h"
#include "MultiMap.h"

//theta(1)
MultiMapIterator::MultiMapIterator(const MultiMap& mm): mm(mm) {
	this->currentElement = 0;
	this->currentNode = mm.elems[this->currentElement].second.head;
	this->counter = 0;
}
//theta(1)
TElemIterator MultiMapIterator::getCurrent() const{
	int k = mm.elems[this->currentElement].first;

	int v = this->currentNode->value;
	return { k,v };

}
//theta(1)
bool MultiMapIterator::valid() const {
	return this->counter != mm.sizeKV;
	
}
//theta(1)
void MultiMapIterator::next() {
	if (this->currentNode->next == NULL)
	{
		this->currentElement = mm.nextPos[this->currentElement];
		this->currentNode = mm.elems[this->currentElement].second.head;
		this->counter++;
	}
	else
	{
		this->currentNode = this->currentNode->next;
		this->counter++;
	}
}
//theta(1)
void MultiMapIterator::first() {
	this->currentElement = mm.headList;
	this->currentNode = this->mm.elems[this->currentElement].second.head;
	this->counter = 0;
}

