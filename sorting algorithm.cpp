#include <cmath>
#include "sorting algorithm.h"

//Intro Sort Implementation in C++ - Programming Algorithms. (2019). Retrieved from https://www.programmingalgorithms.com/algorithm/intro-sort?lang=C%2B%2B

int algorithm::Partition(int* data, int left, int right) {
	int pivot = data[right];
	int temp;
	int i = left;

	comparisons++;
	for (int j = left; j < right; ++j) {
		comparisons += 2;
		if (data[j] <= pivot) {
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
			i++;
		}
	}

	data[right] = data[i];
	data[i] = pivot;

	return i;
}

void algorithm::QuickSortRecursive(int* data, int left, int right) {
	comparisons++;
	if (left < right) {
		int q = Partition(data, left, right);
		QuickSortRecursive(data, left, q - 1);
		QuickSortRecursive(data, q + 1, right);
	}
}

void algorithm::MaxHeapify(int* data, int heapSize, int index) {
	int left = (index + 1) * 2 - 1;
	int right = (index + 1) * 2;
	int largest = 0;

	comparisons++;
	if (left < heapSize && data[left] > data[index])
		largest = left;
	else
		largest = index;

	comparisons += 2;
	if (right < heapSize && data[right] > data[largest])
		largest = right;

	comparisons++;
	if (largest != index) {
		int temp = data[index];
		data[index] = data[largest];
		data[largest] = temp;

		MaxHeapify(data, heapSize, largest);
	}
}

void algorithm::HeapSort(int* data, int count) {
	int heapSize = count;

	comparisons++;
	for (int p = (heapSize - 1) / 2; p >= 0; --p) {
		comparisons++;
		MaxHeapify(data, heapSize, p);
	}

	comparisons++;
	for (int i = count - 1; i > 0; --i) {
		comparisons++;
		int temp = data[i];
		data[i] = data[0];
		data[0] = temp;

		--heapSize;
		MaxHeapify(data, heapSize, 0);
	}
}

void algorithm::InsertionSort(int* data, int count) {
	comparisons++;
	for (int i = 1; i < count; ++i) {
		comparisons += 2;
		int j = i;
		while ((j > 0)) {
			comparisons += 2;
			if (data[j - 1] > data[j]) {
				data[j - 1] ^= data[j];
				data[j] ^= data[j - 1];
				data[j - 1] ^= data[j];

				--j;
			} else {
				break;
			}
		}
	}
}

void algorithm::IntroSort(int* data, int count) {
	int partitionSize = Partition(data, 0, count - 1);


	if (partitionSize < 16) {
		comparisons++;
		InsertionSort(data, count);
	} else if (partitionSize > (2 * log(count))) {
		comparisons+=2;
		HeapSort(data, count);
	} else {
		QuickSortRecursive(data, 0, count - 1);
		comparisons+=3;
	}
}

//Merge Sort - GeeksforGeeks. (2019). Retrieved from https://www.geeksforgeeks.org/merge-sort/
void algorithm::merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	comparisons++;
	for (i = 0; i < n1; i++){
		comparisons++;
		L[i] = arr[l + i];
	}
	comparisons++;
	for (j = 0; j < n2; j++){
		R[j] = arr[m + 1 + j];
		comparisons++;
	}

	i = 0;
	j = 0;
	k = l;
	comparisons+=2;
	while (i < n1 && j < n2) {
		comparisons+=3;
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	comparisons++;
	while (i < n1) {
		comparisons++;
		arr[k] = L[i];
		i++;
		k++;
	}
	comparisons++;
	while (j < n2) {
		comparisons++;
		arr[k] = R[j];
		j++;
		k++;
	}
}

void algorithm::mergeSort(int arr[], int l, int r) {
	comparisons++;
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
