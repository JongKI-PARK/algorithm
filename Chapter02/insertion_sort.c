//insertion_sort.c : insertion sort algorithm
//2022.9.8 park jong ki

#include "algo.h"

//insertion_sort1 sorts array in non-decreasing order
void insertion_sort(int* array, int size) {
	
	for (int j = 1; j < size; j++) {
		int key = array[j];
		int i = j - 1;

		while ((i >= 0) && (array[i] > key)) {
			array[i + 1] = array[i];
			i = i - 1;
		}
		array[i + 1] = key;
	}
}

//insertion_sort2 sorts array in non-increasing order
void insertion_sort2(int* array, int size) {
	
	for (int j = 1; j < size; j++) {
		int key = array[j];
		int i = j - 1;

		while ((i >= 0) && (array[i] < key)) {
			array[i + 1] = array[i];
			i = i - 1;
		}
		array[i + 1] = key;
	}
}

//insertion_sort3 and insert is the recursive version of insertion sort
void insert(int* array, int index) {
	int key = array[index];
	int i = index - 1;

	while((i >= 0) && (array[i] > key)) {
		array[i + 1] = array[i];
		i--;
	}
	array[i + 1] = key;
}

void insertion_sort3(int* array, int size) {
	if (size > 1) {
		insertion_sort3(array, size - 1);
		insert(array, size - 1);
	}
}

