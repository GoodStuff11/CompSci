#include "multTable.h"
#include <iostream>
using namespace std;

multTable::~multTable() {
	// TODO Auto-generated destructor stub
}

multTable::multTable(int x_) {
	x = x_;
	cout << "\t";
	printRow(1);
	for (int row = 1; row <= x; row++) {
		cout << row << "\t";
		printRow(row);
	}
}
/**
 * Prints m
 */
void multTable::printRow(int row) {
	for (int col = 1; col <= x; col++) {
		cout << row * col << "\t";
	}
	cout << endl;
}
