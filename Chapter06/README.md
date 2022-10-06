
# 6. Heapsort

In Chapter 06, another sorting algorithm called Heapsort is introduced. Heapsort's running time is  O(n lg n). Like insertion sort, but unlike merge sort, heapsort sorts in place. Heap is a data structure which is array + rules(the order in which the data is placed).  
The heap data structure is logically a complete binary tree, but physically(actually) an array. Each node of the tree corresponds to an element of the array that stroes the value in the node. An array A that represents a heap. Array A[1  .....  length[A]] consists of length[A] elements. The number of elements in the heap stored whithin array A is heap-size[A] where heap-size[A] <= length[A].  

## Exercises & Problems

### 6. 1-1
> What are the minimum and maximum numbers of elements in a heap of height h?

### 6. 1-2
> Show that an n-element heap has height ⌊lg n⌋. 

### 6. 1-5
> Is an array that is in sorted order a min-heap?

### 6. 1-7
> Show that, with the array representation for storing an n-element heap, the leaves are the nodes indexed by ⌊n/2⌋ + 1, ⌊n/2⌋ + 2, . . . , n.

### 6. 2-1
> Using Figure 6.2 as a model, illustrate the operation of MAX-HEAPIFY(A, 3) on the array A = 27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0. 

### 6. 2-3
> What is the effect of calling MAX-HEAPIFY(A, i) when the element A[i] is larger than its children? 

### 6. 2-4
> What is the effect of calling MAX-HEAPIFY(A, i) for i > heap-size[A]/2? 

### 6. 2-5
> The code for MAX-HEAPIFY is quite efficient in terms of constant factors, except possibly for the recursive call in line 10, which might cause some compilers to produce inefficient code. Write an efficient MAX-HEAPIFY that uses an iterative control construct (a loop) instead of recursion.


## Codes

## References
