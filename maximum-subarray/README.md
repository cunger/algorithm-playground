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
- Find those three subarrays and pick the maximum one.

### Kadane (_O(n)_)

## Compile and run

Running the divide-and-conquer algorithm on the examples:
```
$ make divide-and-conquer
$ ./example
```

Running Kandane's algorithm on the examples:
```
$ make kandane
$ ./example
```
