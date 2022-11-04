
# 7. Quicksort

  Quicksork, like merge sort, is based on the divide-and-conquer paradigm. Merge sort doesn't work in practice because of the auxiliary space that merge sort requires. There are two interesting and important aspects to quicksort. First thing is in place update, and the other is that all the work is in divide step. The key to the quicksort algorithm is the PARTITION procedure which rearranges the subarray A[p ... r] in place.  
  ```
  PARTITION(A, p, r)
  1  x <- A[r]
  2  i <- p - 1
  3  for j <- p to r - 1 
  4       do if A[j] <= x
  5          i < -i + 1
  6          exchange A[i] <-> A[j]
  7  exchange A[i + 1] <-> A[r]
  8  return i + 1
  ```
In n-element array A, PARTITION pick a pivot element x in A and partition the array into subarrays. But remember the pivot is a value, not index.  
<pre>
--------------------------------------
|     <= x      |  x  |     > x      |
--------------------------------------
</pre>
Partition takes Θ(n) time because it looks at every element in the array. It has to look at all values to divide into the subparts of values less than or equal to the pivot and greater than the pivot.  
  ```
  QUICKSORT(A, p, r)
  1  if (p < r)
  2     do q <- PARTITION(A, p, r)
  3        QUICKSORT(A, p, q - 1)
  4        QUICKSORT(A, p, q + 1)
  ```

QUICKSORT 


## Exercises & Problems

### 7. 1-1 
> Using Figure 7.1 as a model, illustrate the operation of PARTITION on the array A = 13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21.

### 7. 1-2 
> What value of q does PARTITION return when all elements in the array A[p ... r] have the same value? Modify PARTITION so that q = (p+r)/2 when all elements in the array A[p ... r] have the same value. 

### 7. 1-3 
> Give a brief argument that the running time of PARTITION on a subarray of size n is Θ(n). 

### 7. 2-1 
> Use the substitution method to prove that the recurrence T (n) = T (n - 1) + Θ(n) has the solution T (n) = Θ(n^2), as claimed at the beginning of Section 7.2.

### 7. 2-2 
> What is the running time of QUICKSORT when all elements of array A have the same value? 

### 7. 2-3 
> Show that the running time of QUICKSORT is Θ(n^2) when the array A contains distinct elements and is sorted in decreasing order.

### 7. 4-1 
> Show that in the recurrence $$$$$$$$$$picture

### 7. 4-2 
> Show that quicksort's best-case running time is Ω(n lg n).

### 7. 4-5 
> The running time of quicksort can be improved in practice by taking advantage of the fast running time of insertion sort when its input is "nearly" sorted. When quicksort is called on a subarray with fewer than k elements, let it simply return without sorting the subarray. After the top-level call to quicksort returns, run insertion sort on the entire array to finish the sorting process. Argue that this sorting algorithm runs in O(nk + n lg(n/k)) expected time. How should k be picked, both in theory and in practice?

### 7-1 (Problems)
> Hoare partition correctness 
> The version of PARTITION given in this chapter is not the original partitioning algorithm. Here is the original partition algorithm, which is due to T. Hoare:
  ```
  HOARE-PARTITION(A, p, r) 
   1 x ← A[p] 
   2 i ← p - 1 
   3 j ← r + 1 
   4 while TRUE 
   5       do repeat j ← j - 1 
   6           until A[j] ≤ x
   7          repeat i ← i + 1 
   8           until A[i] ≥ x
   9          if i < j
  10             then exchange A[i] ↔ A[j] 
  11             else return j
  ```


## Codes

| Algorithm | name of the file(code) | Function name | Simple Explanation |
| :---: | :---: | :---: | :---: |
| QUCIK-SORT | quicksort.c | quicksort() | . |
| QUICK-SORT | quicksort.c | quicksort_h() | quicksort with HOARE-PARTITION |

<br><br>

## References
[1] https://stackoverflow.com/questions/7198121/quicksort-and-hoare-partition  
