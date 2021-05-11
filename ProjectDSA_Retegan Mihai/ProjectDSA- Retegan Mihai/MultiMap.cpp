#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;

// O(cap) (capacity)
int MultiMap::findKeyPos(TKey c)
{
	int current = this->headList;
	while (current != -1 && this->elems[current].first != c)
	{
		current = this->nextPos[current];
	}
	if (current != -1)
		return current;
	else
		return -1;
	
	/*for (int i = 0; i < 30; i++)
	{
		if (this->elems[i].first == c)
		{
			return i;
		}
	}
	return -1;*/
}


// theta(capacity)
MultiMap::MultiMap() {
	this->cap = 30;
	this->len = 0;
	this->headList = -1;
	this->firstEmpty = 0;
	this->sizeKV = 0;
	for (int i = 0; i < 30; i++)
	{
		this->elems[i] = { NULL_TKEY , NULL_DLL };
		this->nextPos[i] = i+1;
	}
	this->nextPos[this->cap-1]=-1;
}

//WC=O(capacity) BC=theta(1)
void MultiMap::add(TKey c, TValue v) {
	if (this->firstEmpty == -1)
	{
		throw ("full");
	}
	else
	{
		int pos = this->findKeyPos(c);
		if (pos == -1) // if key was not found add Key in array
		{
			if (this->isEmpty()) // mm is empty -> insert first key
			{
				int newPositon = this->firstEmpty;
				this->elems[newPositon].first = c;
				VNode* n = new VNode;
				n->value = v;
				n->next = NULL;
				n->previous = NULL;
				//this->elems[newPositon].second.node = n;
				this->elems[newPositon].second.head = n;
				this->elems[newPositon].second.tail = n;
				this->firstEmpty = this->nextPos[this->firstEmpty];
				this->nextPos[newPositon] = this->headList;
				this->headList = newPositon;
				this->len++;
				this->sizeKV++;
			}
			else { // insert new key
				int pozCurrent = 1;
				int NodCurrent = this->headList;
				
				while (NodCurrent != -1 && pozCurrent < this->firstEmpty-1)
				{
					pozCurrent += 1;
					NodCurrent = this->nextPos[NodCurrent];
				}
				if (NodCurrent != -1)
				{
					int newElem = this->firstEmpty;
					this->firstEmpty = this->nextPos[this->firstEmpty];

					this->elems[newElem].first = c;
					VNode* n = new VNode;
					n->value = v;
					n->next = NULL;
					n->previous = NULL;
					//this->elems[newElem].second.node = n;
					this->elems[newElem].second.head = n;
					this->elems[newElem].second.tail = n;
					this->len++;
					
					this->nextPos[newElem] = this->nextPos[NodCurrent];
					this->nextPos[NodCurrent] = newElem;
				}
				this->sizeKV++;
			}
		}
		else // if key was found then add TValue to DLL of that key
		{
			VNode* n = new VNode;
			n->value = v;
			n->previous = this->elems[pos].second.tail;
			this->elems[pos].second.tail->next = n;
			this->elems[pos].second.tail = n;
			this->elems[pos].second.tail->next = NULL;
			this->sizeKV++;

		}

	}

}


//WC=O(capacity) BC=theta(1)
bool MultiMap::remove(TKey c, TValue v) {
	int pos = this->findKeyPos(c);
	if (pos == -1)
	{
		return false;
	}
	else
	{
		if (this->elems[pos].second.tail == this->elems[pos].second.head)// checks if there s only one value left, if so, delete key-value
		{
			int nodC = this->headList;
			int prevNode = -1;
			while (nodC != -1 && this->elems[nodC].first!=c)
			{
				prevNode = nodC;
				nodC = this->nextPos[nodC];
			}	
			// we don`t check if nodC is different from 0 because we already know that the key exists in the elems array so we have actually what to remove
			if (nodC == this->headList)
			{
				this->elems[this->headList].first = NULL_TKEY;
				this->headList = this->nextPos[this->headList];
				this->sizeKV--;
			}
			else
			{
				this->elems[nodC].first = NULL_TKEY;
				this->nextPos[prevNode] = this->nextPos[nodC];
				this->sizeKV--;
			}
				

			this->nextPos[nodC] = this->firstEmpty;
			this->firstEmpty = nodC;
			this->len--;
			return true;
		}
		else // here -> only look for tvalue from dll of a key and delete it
		{
			VNode* currentNode = this->elems[pos].second.head;
			while (currentNode != NULL && currentNode->value != v)
				currentNode = currentNode->next;
			VNode* deletedNode = currentNode;
			if (currentNode != NULL)
			{
				if (currentNode == this->elems[pos].second.head)// if value to be deleted is head
				{
					this->elems[pos].second.head = this->elems[pos].second.head->next;
					this->elems[pos].second.head->previous = NULL;
					this->sizeKV--;
					return true;
				}
				else
				{
					if (currentNode == this->elems[pos].second.tail)// if value to be deleted is tail
					{
						this->elems[pos].second.tail = this->elems[pos].second.tail->previous;
						this->elems[pos].second.tail->next = NULL;
						this->sizeKV--;
						return true;
					}
					else // otherwise (if it s not tail not head)
					{
						currentNode->next->previous = currentNode->previous;
						currentNode->previous->next = currentNode->next;
						this->sizeKV--;
						return true;
					}
				}
			}
			else
				return false;
			
		}
			
		
	}
}

//BC=Theta(1) WC=AC=O(capacity)
vector<TValue> MultiMap::search(TKey c)  {
	int pos = this->findKeyPos(c);
	if (pos == -1)
	{
		return vector<TValue>();
	}
	else
	{
		VNode *current = this->elems[pos].second.head;
		vector<TValue> values;
		while (current != NULL)
		{
			values.push_back(current->value);
			current = current->next;
		}
		return values;
	}

	
}

//WC = AC = BC = theta(1)
int MultiMap::size() const {
	
	return this->sizeKV;
}

//WC = AC = BC = theta(1)
bool MultiMap::isEmpty() const {
	if (this->len == 0)
		return 1;
	else
		return 0;
}
//WC = AC = BC = theta(1)
MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}


MultiMap::~MultiMap() {

}

//void MultiMap::printValues()
//{
//	for (int i = 0; i < 30; i++)
//	{
//		
//		if (this->elems[i].first != NULL_TKEY)
//		{
//			cout << i << ":";
//			VNode* current = this->elems[i].second.head;
//			cout << this->elems[i].first << "\n";
//			while (current!=NULL )
//			{
//				if (this->elems[i].second.tail == this->elems[i].second.head)
//				{
//					printf("only 1 element");
//				}
//				cout << current->value<< " ";
//				current = current->next;
//				
//			}	
//			cout<<"\n";
//		}
//	}
//}