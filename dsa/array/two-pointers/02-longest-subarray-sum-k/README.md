# Longest Subarray sum K

## Brute force

O(n^3)

```python
for i in range(n):
  for j in range(i+1, n):
    if sum(arr[i:j+1]) == k :
      max_len = max(max_len, j - i + 1)

```

## Prefix sums

O(n^2)

```python
for i in range(n):
  for j in range(i+1, n):
    if prefix[j] - prefix[i] == k :
      max_len = max(max_len, j - i + 1)
```

## Running sums

O(n^2), O(1) space

```python
for i in range(n):
  csum = 0
  for j in range(i+1, n):
    csum += arr[j]
    if csum == k :
      max_len = max(max_len, j - i + 1)
```

## Prefix sums lookup

- Hashmap: average O(n), worst O(n^2)
- sorted_map: O(n log n)

```python
prefix_sum_map = dict()
csum = 0
for i in range(n):
  csum += arr[i]

  if !prefix_sum_map[csum] :
    prefix_sum_map[csum] = i;

csum = 0
for i in range(n):
  csum += arr[i]

  if csum == k:
    max_len = max(max_len, i + 1)
    continue

  if prefix_sum_map[csum - k]:
    max_len = max(max_len, i + 1 - prefix_sum_map[csum - k])
    continue
```

## Two pointers

- O(n)
- Doesn't work for negative numbers

```python
i, j = 0, 0

csum = 0
while j < n:
  csum += arr[j]

  if csum == K:
    max_len = max(max_len, j + 1 - i)

  while csum > K:
    csum -= arr[i]
    i++

  if csum < K:
    j++

```
