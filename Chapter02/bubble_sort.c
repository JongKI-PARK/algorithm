// bubble_sort.c : bubble sort
// 2022.10.14 park jong ki

#include "algo.h"

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int* A, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = size - 1; j >= i + 1; j--) {
			if (A[j] < A[j - 1])
				swap(&A[j], &A[j - 1]);
		}
	}
}
