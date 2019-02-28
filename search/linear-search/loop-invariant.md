**Input:** A sequence `A` and a value `v`.

**Output:** The smallest index `i` for which `v` equals `A[i]`,
or `-1` if `v` does not occur in `A`.

```
LINEAR-SEARCH(A, v)
for i = 1 to A.length
  if A[i] equals v
    return i

return -1
```

**Loop invariant:** At each iteration of the loop at position `i`,
the subsequence `A' = A[1, i - 1]` does not contain `v`.

_Initialization:_ At the first iteration with `i = 1`, `A'` is empty,
thus it does not contain `v`.

_Maintenance:_ At each subsequent position `i`: The loop invariant is true at
position `i - 1`, i.e. `v` does not occur in `A[1, i - 2]`. If `v` occurred at
`A[i - 1]`, the loop would have terminated. Since the loop is still running,
the value does not occur at `A[i - 1]`, and thus not in `A[1, i - 1]`.

_Termination:_ The loop terminates at position `i` where either `A[i]` equals
the `v`, in which case `i` is the first occurrence of `v` and is returned,
or `i` is greater than the length of `A`, in which case `-1` is returned.
