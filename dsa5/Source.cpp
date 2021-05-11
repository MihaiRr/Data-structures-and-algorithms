#include "DynamicVector.h"
#include <iostream>
#include <windows.h>
#include "Heap3.h"
#include "ShortTest.h"
#include "ExtendedTest.h"

using namespace std;

bool rel3(TPriority p1, TPriority p2) {
	if (p1 < p2) {
		return true;
	}
	else {
		return false;
	}
}
int main()
{
	testAll();
	testAllExtended();
	return 0;
}