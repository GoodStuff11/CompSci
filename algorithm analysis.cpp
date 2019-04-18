#include <iostream>
#include <stdlib.h>
#include "sorting algorithm.h"
#include <fstream>
using namespace std;

void generate_array(int* array, int size) {
	//change this function as needed
	for (int i = 0; i < size; i++) {
		//array[i] = i;
		//array[i] = rand();
		array[i] = size - i;
	}
}
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
	ofstream file("sortingReversed.csv", ios::out);

	int size = 3;
	file
			<< "Array size,HeapSort comparisons,MergeSort comparisons,InsertionSort comparisons,QuickSort comparisons"
			<< endl;
	for (int k = 0; size < 400; k++) {
		size += 3;
		file << size << ',';
		cout << size << endl;

		int merge[100];
		int heap[100];
		int insertion[100];
		int quick[100];
		for (int reps = 0; reps < 100; reps++) {
			int *x = new int[size];
			generate_array(x, size);
			//print_array(x,size);

			//make copies of x
			int *y = new int[size];
			int *z = new int[size];
			int *w = new int[size];
			for (int i = 0; i < size; i++) {
				y[i] = x[i];
				z[i] = x[i];
				w[i] = x[i];
			}

			comparisons = 0;
			HeapSort(x, size);
			heap[reps] = comparisons;

			comparisons = 0;
			mergeSort(y, 0, size - 1);
			merge[reps] = comparisons;

			comparisons = 0;
			InsertionSort(z, size);
			insertion[reps] = comparisons;

			comparisons = 0;
			QuickSortRecursive(w, 0, size - 1);
			quick[reps] = comparisons;

			delete x;
			delete y;
			delete z;
			delete w;
		}
		file << average(heap, 100) << ',';
		file << average(merge, 100) << ',';
		file << average(insertion, 100) << ',';
		file << average(quick, 100) << endl;
	}
	file.close();
	return 0;
}
