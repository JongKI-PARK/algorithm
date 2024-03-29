
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
Radix sort sorts in the order of *least significant digit* to *most significant digit*. It is essential that the sorting in this algorithm be stable.  
If radix sort sorts from most significant digit, it will not work.  

  ```
  RADIX-SORT(A, d) 
  1 for i ← 1 to d
  2     do use a stable sort to sort array A on digit i
  ```
In radix sort, counting sort is usually used as a stable sorting algorithm. 

#### Radix sort correctness

proof by induction
1. Assume that it is sorted up to the i-1 digit.  
2-1. If the i-th digit is different from each other, it is sorted by the i-th digit regardless of digits 1 ~ i-1.  
2-2. If the i-th digit is the same, the existing order is maintained as a stable sort.  

#### Radix sort analysis
Counting sort takes $\theta(n + k)$ for each digit. Since radix sort performs counting sort for each digit, it takes $\theta(d * (n + k))$.  

### Bucket Sort
Bucket sort runs in linear time when the input is drawn from a uniform distribution. The important part here is that it assumes the condition that the input is generated by a random process that *distributes elements uniformly* over [0, 1). The idea of bucket sort is to divide the interval [0, 1) into n equal-sized subintervals, or buckets, and then distribute the n input numbers into the buckets. 

  ```
  BUCKET-SORT(A) 
  1 n ← length[A] 
  2 for i ← 1 to n
  3     do insert A[i] into list B[⌊n * A[i]⌋] 
  4 for i ← 0 to n - 1 
  5     do sort list B[i] with insertion sort 
  6 concatenate the lists B[0], B[1], . . ., B[n - 1] together in order
  ```

#### Bucket sort correctness

1. For two elements A[i] and A[j] where A[i] <= A[j], element A[i] is placed either into the same bucket as A[j] or into a bucket with a lower index.  
2-1. If they are located in the same bucket, they are sorted by insertion sort.  
2-2. If it is located in another bucket, it is sorted through concatenation because it is already located in a bucket with a small index.  


#### Bucket sort analysis
* Line 1 to 3 takes $\theta(n)$ because it distributes the n input values into the bucket.  
* Line 4 to 5 takes $\theta(1)$. The worst case of insertion sort is O(n^2), but it is strange that it is O(1). The reason is because "the data is assumed to come from the uniform distribution". Assuming that the data has a uniform distribution, each list in B has a constant length, so insertion sort can be executed in constant time.  
* Concatenation in Line 6 takes $\theta(n)$.  

Bucket sort takes O(n) (linear time).  

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
