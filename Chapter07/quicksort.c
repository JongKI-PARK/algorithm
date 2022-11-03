// quicksort.c : quicksort algorithm
// 2022.10.19 park jong ki

#include "algo.h"

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int* array, int p, int r) {
	
	int pivot = array[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (array[j] <= pivot) {
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[r]);
	return i + 1;
}

void quicksort(int* array, int p, int r) {
	if (p < r) {
		int q = partition(array, p, r);
		quicksort(array, p, q - 1);
		quicksort(array, q + 1, r);
	}
}

