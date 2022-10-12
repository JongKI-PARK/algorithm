
# 2. Getting Started   

 Why sorting? : Having a sorted list, the problems can be easier. When finding median(takes constant time), Binary search, Data compression ... etc.  
 
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
INSERTION-SORT algorithm is finding the correct position of A[j] in sorted array A[1 ... j - 1]. While finding the right position, it shifts element in the sorted array to the right one by one. INSERTION-SORT has Θ(n) steps in terms of key positions. Θ(n) swap/compare per steps. So the time complexity of INSERTION-SORT is Θ(n^2). If binary search is used in the process of selecting the correct position in insertion sort, the time complexity will be O(n lgn) in terms of comparison, but it will still be O(n^2) in terms of swap(shift).  

## Exercises & Problems

### Bubble sort
> Show the fun time of each line as shown in the insertion sort, then give the worst/best time of bubble sort
 ```
 BUBBLESORT(A)
 1  for i <- 1 to length[A]
 2      do for j <- length[A] downto i + 1
 3             do if A[j] < A[j - 1]
 4                   then exchange A[j] <-> A[j - 1]
 ```


### 2. 1-2
> Rewrite the INSERTION-SORT procedure to sort into nonincreasing instead of nondecreasing order. 

### 2. 2-2
> Consider sorting n numbers stored in array A by first finding the smallest element of A and exchanging it with the element in A[1]. Then find the second smallest element of A, and exchange it with A[2]. Continue in this manner for the first n - 1 elements of A. Write pseudocode for this algorithm, which is known as selection sort. What loop invariant does this algorithm maintain? Why does it need to run for only the first n - 1 elements, rather than for all n elements? Give the best-case and worst-case running times of selection sort in Θ-notation

### 2. 2-3
> Consider linear search again (see Exercise 2.1-3). How many elements of the input sequence need to be checked on the average, assuming that the element being searched for is equally likely to be any element in the array? How about in the worst case? What are the average-case and worst-case running times of linear search in Θ-notation? Justify your answers

### 2. 3-4
> Insertion sort can be expressed as a recursive procedure as follows. In order to sort A[1 ... n], we recursively sort A[1 ... n -1] and then insert A[n] into the sorted array A[1 ... n - 1]. Write a recurrence for the running time of this recursive version of insertion sort. 

## Codes

## References
