#include "algo.h"

void merge(int* array, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	
	int* left = (int*)malloc(sizeof(int) * (n1 + 1));
	int* right = (int*)malloc(sizeof(int) * (n2 + 1));

	for(int i = 0; i < n1; i++) {
		left[i] = array[p + i];
	}
	
	for(int i = 0; i < n2; i++) {
		right[i] = array[q + 1 + i];
	}
	
	left[n1] = MAX;
	right[n2] = MAX;

	int i = 0;
	int j = 0;

	for(int k = p; k <= r; k++) {
		if(left[i] <= right[j]) {
			array[k] = left[i];
			i++;
		}
		else {
			array[k] = right[j];
			j++;
		}
	}
	free(left);
	free(right);
}

void merge_sort(int* array, int p, int r) {
	if(p < r) {
		int q = (p + r) / 2;
		merge_sort(array, p, q);
		merge_sort(array, q + 1, r);
		merge(array, p, q, r);
	}
}
