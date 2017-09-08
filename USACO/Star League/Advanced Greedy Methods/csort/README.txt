Cow Sorting
===========

Farmer John's N (1 <= N <= 10,000) cows are lined up to be milked
in the evening.  Each cow has a unique "grumpiness" level in the 
range 1...100,000.  Since grumpy cows are more likely to damage 
FJ's milking equipment, FJ would like to reorder the cows in line 
so they are lined up in increasing order of grumpiness. During 
this process, the places of any two cows (not necessarily adjacent) 
can be interchanged. Since grumpy cows are harder to move, it takes 
FJ a total of X+Y units of time to exchange two cows whose 
grumpiness levels are X and Y.

Please help FJ calculate the minimal time required to reorder the 
cows.

PROBLEM NAME: csort

INPUT FORMAT:

* Line 1: A single integer: N.

* Lines 2..N+1: Each line contains a single integer: line i+1
        describes the grumpiness of cow i.

SAMPLE INPUT:

3
2
3
1

INPUT DETAILS:

Three cows are standing in line with respective grumpiness levels 
2, 3, and 1.

OUTPUT FORMAT:

* Line 1: A single line with the minimal time required to reorder 
        the cows in increasing order of grumpiness.

SAMPLE OUTPUT:

7

OUTPUT DETAILS:

2 3 1 : Initial order.   
2 1 3 : After interchanging cows with grumpiness 3 and 1 (time=1+3=4).
1 2 3 : After interchanging cows with grumpiness 1 and 2 (time=2+1=3).
