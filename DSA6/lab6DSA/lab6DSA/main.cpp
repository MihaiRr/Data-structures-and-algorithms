#include <iostream>
#include "Set.h"
#include <assert.h>
#include "ExtendedTest.h"
#include "ShortTest.h"
#include <Windows.h>
using namespace std;


int main() {
	testAll();
	cout << "short test done\n";
	testAllExtended();
	cout << "extended test done\n";
	system("pause");
	return 0;
}