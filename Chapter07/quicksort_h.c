// quicksort_h.c : quicksort algorithm with HOARE-PARTITION
// 2022.10.24 park jong ki

#include "algo.h"

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition_h(int* array, int p, int r) {
	
	int pivot = array[p];
	int i = p - 1;
	int j = r + 1;
	
	while(1) {
		do {
			j = j - 1;
		} while (array[j] > pivot);
		
		do {
			i = i + 1;
		} while (array[i] < pivot);

		if (i < j)
			swap(&array[i], &array[j]);
		else
			return j;
	}
}

void quicksort_h(int* array, int p, int r) {
	if (p < r) {
		int q = partition_h(array, p, r);
		quicksort_h(array, p, q);
		quicksort_h(array, q + 1, r);
	}
}

