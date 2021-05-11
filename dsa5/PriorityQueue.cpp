#include "PriorityQueue.h"




void PriorityQueue::push(TElem e, TPriority p)
{
	this->heap.add({ e,p });
}

Element PriorityQueue::top()
{
	if (this->isEmpty())
		throw std::invalid_argument("");
	return this->heap.minim();
}


Element PriorityQueue::pop()
{
	if (this->isEmpty())
		throw std::invalid_argument("");
	Element elem = this->top();
	this->heap.remove();
	return elem;
}

bool PriorityQueue::isEmpty()
{
	return this->heap.isEmpty();
}

PriorityQueue::~PriorityQueue()
{
}
