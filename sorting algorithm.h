#ifndef SORTING_ALGORITHM_H_
#define SORTING_ALGORITHM_H_

//didnt know how to easily count comparisons, so i made it a class.
class algorithm {
public:
	int comparisons;

	int Partition(int* data, int left, int right);
	void QuickSortRecursive(int* data, int left, int right);
	void MaxHeapify(int* data, int heapSize, int index);
	void HeapSort(int* data, int count);
	void InsertionSort(int* data, int count);
	void IntroSort(int* data, int count);

	void merge(int arr[], int l, int m, int r);
	void mergeSort(int arr[], int l, int r);
};
#endif /* SORTING_ALGORITHM_H_ */
