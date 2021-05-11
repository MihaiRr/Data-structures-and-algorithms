#pragma once
#include <assert.h>
#include <iostream>

template <typename Template>
class DynamicVector
{
private:
	int size;
	int capacity;
	Template* elements;

	void resize();

public:
	DynamicVector(int capacity);
	
	void add(Template element);
	void remove(int position);
	void update(Template& element, int position);
	int find(Template element);
	int getSize();

	Template& operator[](int position);

	~DynamicVector();
};

template<typename Template>
DynamicVector<Template>::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elements = new Template[capacity];
}

template<typename Template>
DynamicVector<Template>::~DynamicVector()
{
	//delete[] this->elements;
}

template<typename Template>
void DynamicVector<Template>::resize()
{
	this->capacity *= 2;
	Template* newElements = new Template[capacity];

	for (int i = 0; i < this->size; i++)
		newElements[i] = this->elements[i];

	delete[] this->elements;
	this->elements = newElements;
}

template<typename Template>
void DynamicVector<Template>::add(Template element)
{
	if (this->size == this->capacity)
		this->resize();
	this->elements[this->size] = element;
	this->size++;
}

template<typename Template>
void DynamicVector<Template>::remove(int position)
{
	for (int i = position; i < this->size - 1; i++)
		this->elements[i] = this->elements[i + 1];
	this->size--;
}

template<typename Template>
void DynamicVector<Template>::update(Template& element, int position)
{
	this->elements[position] = element;
}

template<typename Template>
int DynamicVector<Template>::find(Template element)
{
	for (int i = 0; i <= this->size; i++)
		if (element == this->elements[i])
			return i;
	return -1;
}

template<typename Template>
int DynamicVector<Template>::getSize()
{
	return this->size;
}

template<typename Template>
Template & DynamicVector<Template>::operator[](int position)
{
	return this->elements[position];
}

