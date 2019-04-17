#include <iostream>
#include <stdlib.h>
#include "sorting algorithm.h"
#include <fstream>
using namespace std;

void print_array(int* array, int size) {
	cout << "{";
	for (int i = 0; i < size; i++) {
		cout << array[i];
		if (i < size - 1)
			cout << ',';
	}
	cout << "}" << endl;
}
double average(int* array, int size) {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += (double) array[i];
	}
	return sum / (double) size;
}
int main() {
	algorithm *sort = new algorithm();

	ofstream file("sortingSorted.csv", ios::out);

	int size = 1;
	file
			<< "Array size,HeapSort comparisons,MergeSort comparisons,InsertionSort comparisons"
			<< endl;
	for (int k = 0; size < 50000; k++) {
		size *= 2;
		file << size << ',';
		cout << size << endl;

		int merge[100];
		int heap[100];
		int insertion[100];
		for (int reps = 0; reps < 100; reps++) {
			int *x = new int[size];
			int *y = new int[size];
			int *z = new int[size];
			for (int i = 0; i < size; i++) {
				//x[i] = rand();
				//x[i] = size - i;
				x[i] = i;
				y[i] = x[i];
				z[i] = x[i];
			}

			sort->comparisons = 0;
			sort->HeapSort(x, size);
			heap[reps] = sort->comparisons;

			sort->comparisons = 0;
			sort->mergeSort(y, 0, size - 1);
			merge[reps] = sort->comparisons;

			sort->comparisons = 0;
			sort->InsertionSort(z, size);
			insertion[reps] = sort->comparisons;

			delete x;
			delete y;
			delete z;
		}
		file << average(heap, 100) << ',';
		file << average(merge, 100) << ',';
		file << average(insertion, 100) << endl;
	}
	file.close();
	return 0;
}
