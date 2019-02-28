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

**Loop invariant:** For every iteration `i`, it holds that
```
LINEAR-SEARCH(A, v) = LINEAR-SEARCH(A[i...A.length], v)
```

_Initialization:_ Before the first iteration `i = 1`, `A = A[1...A.length]`,
so the invariant is trivially true.

_Maintenance:_ At each subsequent position `i`: The loop invariant is true at
position `i-1`, i.e.
```
LINEAR-SEARCH(A, v) = LINEAR-SEARCH(A[i-1...A.length])
````
If `v` occurred at `A[i-1]`, the loop would have terminated. Since the loop
is still running, `v` does not occur at `A[i-1]`, and thus the invariant
also holds for `A[i...A.length]`.

_Termination:_ The loop terminates at position `i` when either `A[i]` equals `v`,
or `i` is greater than the length of `A`.
