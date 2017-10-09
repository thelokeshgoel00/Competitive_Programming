Claustrophobic Cows 2
=====================

Farmer John has acquired a set of N (2 <= N <= 50,000) touchy cows
who are conveniently numbered 1..N. They really hate being too close
to other cows. A lot.

FJ has recorded the integer X_i,Y_i coordinates of every cow i (1
<= X_i <= 10,000; 1 <= Y_i <= 10,000).

FJ would like to spread them out a bit. Determine which two are closest
together and print their cow id numbers (i) in numerical order.

By way of example, consider this field of cows (presented on a
typewriter grid that has slightly different proportions than you
might expect):

                    10 | . . . . . . . 3 . . . . .
                     9 | . 1 . . 2 . . . . . . . .
                     8 | . . . . . . . . . . . . .
                     7 | . . . . . . . . . . 4 . .
                     6 | . . . . . . 9 . . . . . .
                     5 | . 8 . . . . . . . . . . .
                     4 | . . . . . 7 . . . . . . .
                     3 | . . . . . . . . . 5 . . .
                     2 | . . . . . . . . . . . . .
                     1 | . . . . 6 . . . . . . . .
                     0 ---------------------------
                                           1 1 1 1
                       0 1 2 3 4 5 6 7 8 9 0 1 2 3

Quick visual inspection shows that cows 7 and 9 are closest together
(the distance separating them is sqrt(1*1+2*2) = sqrt(5), so the
output would be '7 9' on a single line (without quotes, of course).

PROBLEM NAME: claust2

INPUT FORMAT:

* Line 1: A single integer: N
* Lines 2..N+1: Line i contains the coordinates of cow i expressed as
        two space-separated integers: X_i and Y_i

SAMPLE INPUT:

9
2 9
5 9
8 10
11 7
10 3
5 1
6 4
2 5
7 6

INPUT DETAILS:

As in the example.

OUTPUT FORMAT:

* Line 1: The two numerical IDs of the closest pair of cows (sorted)
       If there are more than one solution, output the one that is 
       lexicographically first.

SAMPLE OUTPUT:

7 9
