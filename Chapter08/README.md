
# 8. Sorting in Linear Time

### Counting Sort
The basic idea of COUNTING-SORT is to determine, for each input element x, the number of elements less than x. This information can be used to place element x directly into its position in the output array.

  ```
  COUNTING-SORT(A, B, k) 
   1 for i ← 0 to k
   2     do C[i] ← 0 
   3 for j ← 1 to length[A] 
   4     do C[A[j]] ← C[A[j]] + 1 
   5 ▹ C[i] now contains the number of elements equal to i. 
   6 for i ← 1 to k
   7     do C[i] ← C[i] + C[i - 1] 
   8 ▹ C[i] now contains the number of elements less than or equal to i. 
   9 for j ← length[A] downto 1 
  10     do B[C[A[j]]] ← A[j] 
  11        C[A[j]] ← C[A[j]] - 1 
  ```

Counting sort needed auxiliary space according to the key range. For decimal digits, only 10 places(0, 1, 2, 3, ....9) are used. Radix sort sorts the least significant digit first. This algorithm does stable sort. Stable means that the output is affected by the input. When sorting, if there is the same number, the existing order is maintained.  


### Radix Sort
Radix sort sorts in the order of *least significant digit* to *most significant digit*. It is essential that the digit sorts in this algorithm be stable.  

  ```
  RADIX-SORT(A, d) 
  1 for i ← 1 to d
  2     do use a stable sort to sort array A on digit i
  ```


## Exercises & Problems

### 8. 3-1 
> Using Figure 8.3 as a model, illustrate the operation of RADIX-SORT on the following list of English words: COW, DOG, SEA, RUG, ROW, MOB, BOX, TAB, BAR, EAR, TAR, DIG, BIG, TEA, NOW, FOX.  

### 8. 3-2 (considered only quick sort is stable or not) 
> Which of the following sorting algorithms are stable: insertion sort, merge sort, heapsort, and quicksort? Give a simple scheme that makes any sorting algorithm stable. How much additional time and space does your scheme entail?  

### 8. 3-4 
> Show how to sort n integers in the range 0 to $n^2 - 1$ in O(n) time.  

### 8. 4-1
> Using Figure 8.4 as a model, illustrate the operation of BUCKET-SORT on the array A = <.79, .13, .16, .64, .39, .20, .89, .53, .71, .42>.  

### 8. 4-2 
> What is the worst-case running time for the bucket-sort algorithm? What simple change to the algorithm preserves its linear expected running time and makes its worst-case running time $O(n \log_2 n)$?

## Codes

## References
[1] https://www.quora.com/How-do-I-find-number-of-digit-in-2-n  
