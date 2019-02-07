#include <iostream>

#include "multTable/multTable.h"
#include "inputs/inputs.h"

using namespace std;

int main() {
	multTable *t = new multTable(10);
	delete t;

	input();
}
