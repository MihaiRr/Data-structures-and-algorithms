#include "Tests.h"
#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <assert.h>
#include <vector>
#include<iostream>

void testAll() {
	MultiMap m;
	//m.printNext();
	m.add(1, 100);
	m.add(2, 200);
	m.add(3, 300);
	m.add(1, 500);
	m.add(1, 600);
	m.add(1, 300);
	m.add(1, 200);
	m.add(2, 800);
	m.add(3, 500);
	m.add(2, 600);
	m.add(3, 700);
	m.add(4, 800);
	m.add(5, 900);
	m.add(4, 8000);
	
	assert(m.size() == 14);
	
	assert(m.remove(6, 600) == false);
	assert(m.remove(1, 500) == true);
	assert(m.remove(2, 200) == true);
	assert(m.remove(1, 5100) == false);
	assert(m.remove(3, 700) == true);
	assert(m.remove(4, 8000) == true);
	assert(m.remove(4, 800) == true);
	assert(m.remove(5, 900) == true);
	
	assert(m.remove(2, 800) == true);
	assert(m.remove(2, 600) == true);
	
	//m.printValues();
	assert(m.size() == 6);
	//m.printNext();
	m.add(1, 500);
	m.add(1, 700);
	m.add(2, 300);
	

	vector<TValue> v,v1;
	v=m.search(6);
	assert(v.size()==0);

	v=m.search(1);
	//m.printValues();
	assert(v.size()==6);

	m.add(1, 500);
	m.add(1, 500);

	v = m.search(1);
	assert(v.size() == 8);
	v1 = { 100, 600, 300, 200, 500, 700, 500, 500 };
	assert(v == v1);


	m.add(4, 800);

	v = m.search(4);
	v1 = { 800 };
	//m.printValues();
	assert(v.size() == 1);
	assert(v == v1);

	v = m.search(1);
	assert(v != v1);

	assert(m.isEmpty() == false);

	MultiMapIterator im = m.iterator();
	assert(im.valid() == true);
	while (im.valid()) {
		im.getCurrent();
		im.next();
	}
	assert(im.valid() == false);
	im.first();
	assert(im.valid() == true);
}
