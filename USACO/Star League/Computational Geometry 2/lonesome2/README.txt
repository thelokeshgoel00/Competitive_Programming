Lonesome Partners 2
===================

Bessie and the rest of the herd totaling N (2 <= N <= 50,000) cows
have gone to the dance. For the cows-only part of the dance, two
cows are chosen as the "Belles of the Ball". Farmer John records
the X,Y coordinates (0 <= X_i <= 10,000; 0 <= Y_i <= 10,000) of all
the cows in the dance hall and then asks you to determine the indices
of the two cows who are farthest apart. Distance is the normal 
cartesian distance calculated as the square root of the sum of the 
squares of the differences in the row and column coordinates.

In a dance with just eight cows:

 8 | . C . . . . . . . .
 7 | . . . . . . . . . .
 6 | . C . . . . . . . .
 5 | . . . C C . C . . .
 4 | . . . . C . . . . .
 3 | . . C . . . . . . .
 2 | . . . . . . . . . .
 1 | . . . . . . . . . C
 0 +--------------------
   0 1 2 3 4 5 6 7 8 8 9

Farmer John hopes you would choose the cows at 2,8 and 9,1 as
farthest apart.

PROBLEM NAME: lonesome2

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 contains the integer coordinate location of
        cow i: X_i and Y_i

SAMPLE INPUT:

8
2 6
3 3
2 8
4 5
7 5
5 5
9 1
5 4

OUTPUT FORMAT:

* Line 1: Two sorted integers that are the indices of the two cows
       that are located farthest apart. If there are more than one 
       solution, output the one that is lexicographically first.

SAMPLE OUTPUT:

3 7

OUTPUT DETAILS:

Cow #3 and Cow #7 are the cow numbers of the cows from the example in the text.
