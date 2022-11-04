
# 8. Sorting in Linear Time

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

  ```
  RADIX-SORT(A, d) 
  1 for i ← 1 to d
  2     do use a stable sort to sort array A on digit i
  ```


## Exercises & Problems

## Codes

## References
