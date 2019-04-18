#ifndef SORTING_ALGORITHM_H_
#define SORTING_ALGORITHM_H_

//https://stackoverflow.com/questions/31925442/defining-an-extern-variable-in-the-same-header-file
extern int comparisons;

int Partition(int* data, int left, int right);
void QuickSortRecursive(int* data, int left, int right);
void MaxHeapify(int* data, int heapSize, int index);
void HeapSort(int* data, int count);
void InsertionSort(int* data, int count);
void IntroSort(int* data, int count);

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

#endif /* SORTING_ALGORITHM_H_ */
