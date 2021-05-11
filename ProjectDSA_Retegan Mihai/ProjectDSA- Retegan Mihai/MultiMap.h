#pragma once
#include<vector>
#include<utility>
#include<iostream>


using namespace std;

typedef int TKey;
typedef int TValue;

 struct VNode
{
	int value;
	VNode* next;
	VNode* previous;
	VNode() { this->value = -11111; };
 };

 struct DLL
 {
	 //VNode* node;
	 VNode* tail;
	 VNode* head;
	 DLL() {};
 };


#define NULL_TKEY -11111
#define NULL_TVALUE -11111
#define NULL_VNODE VNode()
#define NULL_DLL DLL()
#define NULL_TELEM std::pair<TKey, DLL>(NULL_TVALUE,NULL_DLL)
#define NULL_TELEMITERATOR std::pair<TKey, TValue> (NULL_TKEY, NULL_TVALUE)

 typedef std::pair<TKey, DLL> TElem;
typedef std::pair<TKey, TValue> TElemIterator;

class MultiMapIterator;

class MultiMap
{
	friend class MultiMapIterator;
private:
	TElem elems[30]; // Elements of singley linked list on array
	int nextPos[30]; // array next position form singley linked list
	
	int cap; // capacity of arrays
	int len; // how many keys are actually in the arrays
	int sizeKV;// how many values are in total
	int headList; // head of list	
	int firstEmpty; // first empty position on array
 
	int findKeyPos(TKey c); // find position of a key in elems array
	
public:
	//constructor
	MultiMap();
	
	
	//adds a key value pair to the multimap 
	void add(TKey c, TValue v);

	//removes a value from a dll of a key or key+value(only one left)
	//returns true if the pair was removed (if it was in the multimap) and false otherwise
	bool remove(TKey c, TValue v);

	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
	vector<TValue> search(TKey c) ;

	//returns the number of keys
	int size() const;

	//checks whether the multimap is empty
	bool isEmpty() const;

	//returns an iterator for the multimap
	MultiMapIterator iterator() const;

	//descturctor
	~MultiMap();


	/*void printValues();
	void printNext() { for (int i = 0; i < cap; i++) { std::cout << nextPos[i] << " "; } }
	*/
};

