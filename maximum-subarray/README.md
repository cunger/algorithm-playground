## Problem

Given an array of integers, find a contiguous subarray with the largest sum of all its elements.

## Examples

* `[ -2, 4, -1, 2, 1, -5 ] -> [ 4, -2, 2, 1 ]`
* `[ 1, -2, 3 ] -> [ 3 ]`
* Edge case: all negatives: `[ -1, -2, -3 ] -> []`
* Edge case: all positives: `[ 1, 2, 3, 4 ] -> [ 1, 2, 3, 4 ]`
* Edge case: empty array: `[] -> []`

## Approaches

### Divide and conquer (`O(n log n)`)

- Divide array into two subarrays.
- Possibilities:
  - Maximum subarray is entirely in left or right subarray -> Instance of the same problem
  - Maximum subarray crosses the middle point -> Needs to be found non-recursively
- Find those three subarrays and pick the maximum one.

### Kadane (`O(n)`)
