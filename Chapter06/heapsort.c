// heapsort.c : heap sort algorithm
// 2022.10.19 park jong ki
// to implement heapsort algorithm in c, the heapsize arguement should be passed additionally
// this is because the array length and the heap size can be different (for scalability)

#include "algo.h"

int PARENT(int index) {
	assert(index > 0);
	return index / 2;
}

int LEFT(int index) {
	return (2 * index);
}

int RIGHT(int index) {
	return (2 * index + 1);
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void max_heapify(int* array, int heapsize, int index) {
	int l = LEFT(index);
	int r = RIGHT(index);
	int largest = index;

	if ((r <= heapsize - 1) && (array[index] < array[r])) {
		largest = r;
	}
	if ((l <= heapsize - 1) && (array[largest] < array[l])) {
		largest = l;
	}
	
	if (largest != index) {
		swap(&array[largest], &array[index]);
		max_heapify(array, heapsize, largest);
	}
}

void build_maxheap(int* array, int heapsize) {
	int i = PARENT(heapsize - 1);
	for ( ; i >= 0; i--) {
		max_heapify(array, heapsize, i);
	}
}

void heapsort(int* array, int heapsize) {
	if (heapsize <= 0)
		exit(1);

	build_maxheap(array, heapsize);
	int i = heapsize - 1;
	for ( ; i > 0; i--) {
		swap(&array[0], &array[i]);
		heapsize--;
		max_heapify(array, heapsize, 0);
	}
}

