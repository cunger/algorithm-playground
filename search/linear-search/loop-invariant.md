```
LINEAR-SEARCH(A, value)
for i = 1 to A.length
  if A[i] equals value
    return i

return -1
```

**Loop invariant:** At each iteration of the loop with position i,
the subsequence A' = A[1, i - 1] does not contain the value.

_Initialization:_ At the first iteration i = 1, A' is empty, thus it
does not contain the value.

_Maintenance:_ At position i: The loop invariant is true at position i - 1,
i.e. the value does not occur in A[1, i - 2]. If value occurred at A[i - 1],
the loop would have terminated. Since the loop is still running,
the value does not occur at A[i - 1], and thus not in A[1, i - 1].

_Termination:_ The loop terminates at position i, where either A[i] equals
the value, in which case i is the first occurrence of the value and is returned,
or i is greater than the length of A, in which case -1 is returned.
