#include "Heap3.h"
#include <algorithm>

using namespace std;

void Heap3::sift(int vertex) // O(log3(size of heap))
{
	int son;
	do
	{
		son = 0;
		int left = vertex * 3 - 1;
		int mid = vertex * 3;
		int right = vertex * 3 + 1;

		if (left < this->elems.getSize())
		{
			son = left;

			if (mid < this->elems.getSize())
				if (this->r(this->elems[mid].second, this->elems[son].second))
					son = mid;

			if (right < this->elems.getSize())
				if (this->r(this->elems[right].second, this->elems[son].second))
					son = right;

			if (this->r(this->elems[vertex].second, this->elems[son].first))
				son = 0;
		}
		

		if(son != 0)
		{
			swap(this->elems[son], this->elems[vertex]);
			vertex = son;
		}


	} while (son);

}

void Heap3::percolate(int vertex)// O(log3(size of heap))
{
	int father = this->father(vertex);
	while (vertex > 1 && this->r(this->elems[vertex].second, this->elems[father].second))
	{
		swap(this->elems[vertex], this->elems[father]);
		vertex = father;
		father = this->father(vertex);
	}
}

int Heap3::father(int vertex) // theta(1)
{
	return (vertex + 1) / 3;
}

Heap3::Heap3(Relation r)
{
	this->r = r;
	this->elems.add({ 0,0 });
}

void Heap3::add(Element elem) // O(log3(size of heap))
{
	this->elems.add(elem);
	this->percolate(this->elems.getSize() - 1);
}

Element Heap3::minim() // theta(1);
{
	return this->elems[1];
}

void Heap3::remove()
{
	swap(this->elems[1], this->elems[this->elems.getSize() - 1]);
	this->elems.remove(this->elems.getSize() - 1);
	this->sift(1);
}


bool Heap3::isEmpty()
{
	if (this->elems.getSize() == 1)
		return true;
	else return false;
}

Heap3::~Heap3()
{

}
