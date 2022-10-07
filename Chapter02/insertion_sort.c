//insertion_sort.c : insertion sort algorithm
//2022.9.8 park jong ki

#include "algo.h"

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
