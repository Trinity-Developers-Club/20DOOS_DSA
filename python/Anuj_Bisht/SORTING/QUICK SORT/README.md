# QUICK SORT
- It is based on Divide and Conquer Paradigm.
- It is not inplace and not stable sort.
- It is the most practically used algorithm.
- It consumes relatively lower resources during execution.

## Algorithm

### quicksort()
```md
quicksort(A, P, R)
{
  if(P < R)
  {
    Q = partition(A, P, R);
    quicksort(A, P, Q-1);
    quicksort(A, Q+1, R);
  }
}
```

### partition()
```md
partition(A, P, R)
{
  pivot = A[R];
  i = P - 1;
  for(j = P to R - 1)
  {
    if(A[j] <= pivot)
    {
      i++;
      swap(A[i], A[j]);
    }
  }
  swap(A[i+1], A[R];
  return i+1;
}
```

## Space Complexity
Best Case: O(logn) <br>
Average Case: O(logn) <br>
Worst Case: O(n)

## Time Complexity
Best Case: O(logn) <br>
Average Case: O(logn) <br>
Worst Case: O(n)
