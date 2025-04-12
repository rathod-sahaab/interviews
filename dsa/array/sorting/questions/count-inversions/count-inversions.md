# Count inversions

Geeks for geeks: [https://www.geeksforgeeks.org/inversion-count-in-array-using-merge-sort/](https://www.geeksforgeeks.org/inversion-count-in-array-using-merge-sort/)

```
Given an integer array arr[] of size n, find the inversion count in the array. Two array elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Input: arr[] = {4, 3, 2, 1}
Output: 6
Explanation:

Input: arr[] = {1, 2, 3, 4, 5}
Output: 0
Explanation: There is no pair of indexes (i, j) exists in the given array such that arr[i] > arr[j] and i < j

Input: arr[] = {10, 10, 10}
Output: 0
```

## Aproaches

1. Nested loops time: O(n^2), space: O(1)
2. Merge sort O(n log n) time, space: O(n)
