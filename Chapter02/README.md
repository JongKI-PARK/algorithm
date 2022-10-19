
# 2. Getting Started   

Why sorting? : Having a sorted list, the problems can be easier. When finding median(takes constant time), Binary search, Data compression ... etc. Let's begin with INSERTION-SORT Algorithm.  

 ```
 INSERTION-SORT(A)
 1  for j >- 2 to length[A]
 2      do key <- A[j]
 3         // Insert A[j] into the sorted sequence A[1 ... j - 1]
 4         i <- j - 1
 5         while i > 0 and A[i] > key
 6               do A[i + 1] <- A[i]
 7                  i <- i - 1
 8         A[i + 1] <- key
 ```
INSERTION-SORT algorithm is finding the correct position of A[j] in sorted array A[1 ... j - 1]. To find the right position of newly inserted element, it shifts element in the sorted array to the right one by one. INSERTION-SORT has $Θ(n)$ steps in terms of finding the key positions, $Θ(n)$ swap/compare per steps. So the time complexity of INSERTION-SORT is $Θ(n^2)$. If binary search is used in the process of selecting the correct position in insertion sort, the time complexity will be $O(n lgn)$ in terms of comparison, but it will still be $O(n^2)$ in terms of swap(shift).  

<br>
Insertion sort uses an incremental approach: insert a single element A[j] into already sorted array A[1 ... j - 1]. There is another approach known as divide and conquer. Divide and conquer approach breaks the problem into several subproblems.  
 
 ```
 MERGE(A, p, q, r)
  1  n1 <- q - p - 1
  2  n2 <- r - q
  3  create arrays L[1 ... n1 + 1] and R[1 ... n2 + 1]
  4  for i <- 1 to n1
  5      do L[i] <- A[q + i - 1]
  6  for j <- 1 to n2
  7      do R[j] <- A[q + j]
  8  L[n1 + 1] <- ∞
  9  R[n2 + 1] <- ∞
 10  i ← 1 
 11  j ← 1 
 12  for k ← p to r
 13      do if L[i] ≤ R[j] 
 14            then A[k] ← L[i] 
 15                 i ← i + 1 
 16            else A[k] ← R[j] 
 17                 j ← j + 1
 ```
 
MERGE procedure takes $Θ(n)$ time complexity. It takes $Θ(n)$ time to merge two sorted arrays into one sorted array.  

 ```
 MERGE-SORT(A, p, r) 
  1  if p < r
  2  then q ← ⌊(p + r)/2⌋
  3  MERGE-SORT(A, p, q) 
  4  MERGE-SORT(A, q + 1, r) 
  5  MERGE(A, p, q, r)
 ```
Continuing to divide a given array in half until there is one element takes $Θ(lg^n)$ time. So the overall time complexity of the MERGE-SORT algorithm is $Θ(n lg^n)$. The recursion relation of the Merge sort is $T(n) = 2T(n/2) + Θ(n)$. From the recursion tree of the MERGE-SORT make, we can get the idea of $Θ(n lg^n)$ intuitively. The complexity of it's merge step has $Θ(n)$. The height of the recursion tree will be $lg^n$. The overall time T(n) will be $Θ(n lg^n)$.  

<br>
From this point of view, it may seem that insertion sort is unnecessary. But the one big advantage of INSERTION-SORT over MERGE-SORT is that it doesn't need auxiliary space. INSERTION-SORT does in-place update. The MERGE-SORT has to make a copy of the array to do the recursion and put it back to the array. MERGE-SORT needs $Θ(n)$ auxiliary space.  

## Exercises & Problems

### Bubble sort
> Show the run time of each line as shown in the insertion sort, then give the worst/average time of bubble sort
 ```
 BUBBLESORT(A)
 1  for i <- 1 to length[A] - 1
 2      do for j <- length[A] downto i + 1
 3             do if A[j] < A[j - 1] 
 4                   then exchange A[j] <-> A[j - 1]
 ```

|c|times|  
| :---: | :------: |
| c<sub>1</sub> | n |  
| c<sub>2</sub> | $\displaystyle\sum_{k=1}^{n-1}{(n-k+1)}$ |  
| c<sub>3</sub> | $\displaystyle\sum_{k=1}^{n-1}{(n-k)}$ |  
| c<sub>4</sub> | $\displaystyle\sum_{k=1}^{n-1}{t_k}$ |  

Best case of the bubble sort is when $t_k$ is 0. Worst case is when $t_k$ to be (n - k). In both cases, the time complexity of the Bubble sort is $Θ(n^2)$.  

### 2. 1-2
> Rewrite the INSERTION-SORT procedure to sort into nonincreasing instead of nondecreasing order. 

The algorithm INSERTION-SORT at the top of this page is to sort the array into non decreasing order. Here is the algorithm that sorts the array into non increasing order.
 ```
 INSERTION-SORT(A)
 1  for j <- 2 to length[A]
 2      key <- A[j]
 3      i <- j - 1
 4      while i > 0 and A[i] < key
 5            A[i + 1] <- A[i]
 6            i <- i - 1
 7      A[i + 1] <- key
 ```
     
### 2. 2-2
> Consider sorting n numbers stored in array A by first finding the smallest element of A and exchanging it with the element in A[1]. Then find the second smallest element of A, and exchange it with A[2]. Continue in this manner for the first n - 1 elements of A. Write pseudocode for this algorithm, which is known as selection sort. What loop invariant does this algorithm maintain? Why does it need to run for only the first n - 1 elements, rather than for all n elements? Give the best-case and worst-case running times of selection sort in Θ-notation

 ``` 
 SELECTION-SORT(A)
 1  for i <- 1 to length[A] - 1
 2      key <- A[i]
 3      min-index <- i
 4      for j <- i to length[A]
 5          if A[j] < key
 6             key <- A[j]
 7             min-index <- j
 8      if min-index != i
 9         exchange A[i] <-> A[min-index]
 ```

Index i indicates the position where minimum element in A[i ... n] will take place. The elements in A[1 ... i - 1] are not only smaller than all the elements in A[i ... n] but also are in sorted order. The loop in line 1 will run only for the first n - 1 elements because the last element will be and should be the biggest element. So it is the place where it should be. Both best case and worst case of selection sort is $Θ(n^2)$.  

### 2. 2-3
> Consider linear search again (see Exercise 2.1-3). How many elements of the input sequence need to be checked on the average, assuming that the element being searched for is equally likely to be any element in the array? How about in the worst case? What are the average-case and worst-case running times of linear search in Θ-notation? Justify your answers

For linear search, $n\over 2$ searches will be required on average. The worst case is when there is no element in the array, and a comparison is made with all elements of the array. Both cases has $Θ(n^2)$ run time.  

### 2. 3-4
> Insertion sort can be expressed as a recursive procedure as follows. In order to sort A[1 ... n], we recursively sort A[1 ... n -1] and then insert A[n] into the sorted array A[1 ... n - 1]. Write a recurrence for the running time of this recursive version of insertion sort.  
 
 ```
 INSERT(A, index)
 1  key <- A[index]
 2  i <- index - 1
 3  while i > 0 and A[i] > key
 4        A[i + 1] <- A[i]
 5        i <- i - 1
 6  A[i + 1] <- key
 
 INSERTION-SORT(A, size)
 1  if (size > 0)
 2     INSERTION-SORT(A, size - 1)
 3     INSERT(A, size - 1)
 ```
The recursive version of insertion sort can be expressed by $T(n) = T(n - 1) + Θ(n)$ which has $Θ(n^2)$ running time.  

## Codes

Codes(Written in C) for Insertion sort, Bubble sort Selection sort and Merge sort are included.  

| Algorithm | name of the file(code) | Simple Explanation |
| :---: | :---: | :---: |
| INSERTION-SORT | insertion_sort1.c | sorting in non-decreasing order |
| INSERTION-SORT | insertion_sort2.c | sorting in non-increasing order |
| INSERTION-SORT | insertion_sort3.c | recursive version of selection sort algorithm (sorting in non-decreasing order) |
| BUBBLE-SORT | bubble_sort.c | . |
| SELECTION-SORT | selection_sort.c | . |
| MERGE-SORT | merge_sort.c | . |

## References
