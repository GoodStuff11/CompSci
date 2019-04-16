#define SIZE 10000
#include <iostream>
#include <stdlib.h>
#include "sorting algorithm.cpp"

using namespace std;

void print_array(int* array,int size){
	cout << "{";
	for (int i=0;i<size;i++){
		cout << array[i];
		if (i<size-1)
			cout << ',';
	}
	cout << "}" << endl;
}
int main() {
	int x[SIZE] = new int[SIZE];
	for (int i=0;i<SIZE;i++){
		x[i] = rand();
	}

	//mergeSort(x,0,size-1);
	IntroSort(x,SIZE);
	print_array(x,SIZE);
	return 0;
}
