# Maximum subarray

## Problem

Given an array of integers, find the maximum sum of elements of a contiguous subarray.

## Examples

* `[ 1, -2, 3 ] -> 3` (with `[ 3 ]` the subarray)
* `[ -2, 4, -1, 2, 1, -5 ] -> 6` (with `[ 4, -1, 2, 1 ]` the subarray)
* `[ -2, -3, 4, -1, -2, 1, 5, -3 ]` (with `[ 4, -1, -2, 1, 5 ]` the subarray)
* Edge case: empty array: `[] -> 0` (with `[]` the subarray)
* Edge case: all negatives: `[ -1, -2, -3 ] -> 0` (with `[]` the subarray)
* Edge case: all positives: `[ 1, 2, 3, 4 ] -> 10` (with `[ 1, 2, 3, 4 ]` the subarray)

## Approaches

### Divide and conquer (_O(n log n)_)

- Divide array into two subarrays.
- Possibilities:
  - Maximum subarray is entirely in left or right subarray -> Instance of the same problem
  - Maximum subarray crosses the middle point -> Needs to be found non-recursively
- Find the maximum sums of those three subarrays and pick the greatest one.

### Kadane (_O(n)_)

- Pick each index as end index.
- Determine the maximum sum until that end index: add the element at that index and reset to zero whenever the sum gets negative (this works like moving the left index of the maximum subarray to the right).
- Update and memorize the greatest of those maximum sums.

## Compile and run

Running the divide-and-conquer algorithm on the examples:
```
$ make divide-and-conquer
$ ./example
```

Running Kadane's algorithm on the examples:
```
$ make kadane
$ ./example
```
