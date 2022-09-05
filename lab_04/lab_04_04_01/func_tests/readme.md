# Tests for lab_04 task 4
## INPUT:
* ##### char str - line of symbols
## OUTPUT:
* ##### YES / NO
## POSITIVE TESTS:
1. NO, tabs before, tabs after, "-5-ew" (invalid input E_FORMAT)
2. NO, tabs before, tabs after, "--5" (invalid input PLUS_MINUS_PASS)
3. NO, tabs before, tabs after, "+3. 2" (invalid input SPACES)
4. NO, tabs before, "-.0.2" (invalid input POINT)
5. NO, "+." (invalid input FIRST_SYMBOL)
6. NO, tabs before, "e" (invalind input FIRST_SYMBOL)
7. YES, tabs before, tabs after ".12e-8"
8. NO, empty line
9. YES, tabs before, tabs after, "-8.12E-213"
## NEGATIVE TESTS:
1. overflow, length of input > 256
