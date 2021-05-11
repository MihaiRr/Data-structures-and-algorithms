#include "Test.h"
#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <assert.h>

bool r2(TComp e1, TComp e2) {
	if (e1 <= e2) {
		return true;
	}
	else {
		return false;
	}
}


void testAll() { 
	std::string vverif[5];
	int iverif;
	TComp e;

	SortedSet s1(r2);
	assert(s1.add("Name1") == true);
	assert(s1.add("Name2") == true);
	assert(s1.add("Name3") == true);
	SortedSetIterator it1 = s1.iterator();
	it1.first();
	e = it1.getCurrent();
	iverif = 0;
	vverif[iverif++] = e;
	it1.next();
	while (it1.valid()) {
		assert(e < it1.getCurrent());
		e = it1.getCurrent();
		vverif[iverif++] = e;
		it1.next();
	}
	assert((vverif[0] == "Name1") && (vverif[1] == "Name2") && (vverif[2] == "Name3"));


	SortedSet s(r2);
	//return;
	assert(s.isEmpty() == true);
	assert(s.size() == 0);
	assert(s.add("Name4") == true);
	assert(s.add("Name5") == true);
	assert(s.add("Name10") == true);
	assert(s.add("Name7") == true);
	assert(s.add("Name4") == false);
	assert(s.add("Name10") == false);
	assert(s.add("Name21") == true);
	assert(s.size() == 5);
	assert(s.search("Name10") == true);
	assert(s.search("Name16") == false);
	assert(s.remove("Name4") == true);
	assert(s.remove("Name6") == false);
	assert(s.size() == 4);

	SortedSetIterator it = s.iterator();
	iverif = 0;
	it.first();
	e = it.getCurrent();
	vverif[iverif++] = e;
	it.next();
	while (it.valid()) {
		assert(r2(e, it.getCurrent()));
		e = it.getCurrent();
		vverif[iverif++] = e;
		it.next();
	}
	assert((vverif[0] == "Name5") && (vverif[1] == "Name7") && (vverif[2] == "Name3"));

}

