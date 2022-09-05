# Tests for lab_02 task 2 
## INPUT:
* ##### size_t n - length of array
* ##### int a[i] - each element of array
## OUTPUT:
* ##### int b - array of prime elemets of a
## POSITIVE TESTS:
1. common test, 1 <= n <= 10, prime elems exist
2. common test, n = 1, prime elem exist
3. check test, 1 <= n <= 10, prime elem exist, negative elem exist
## NEGATIVE TESTS:
1. wrong input, n <= 0
2. worng input, n > 10
3. wrong input, 1 <= n <= 10, elem has wrong type
4. no prime elems
