Crazy Fences
============

After visiting a modern art museum, Farmer John decides to re-design his
farm by moving all of the N (1 <= N <= 1000) fences between his pastures! 
Each fence is describe by a line segment in the 2D plane.  If two fences
meet, they do so only at their endpoints.  Each fence touches exactly two
other fences, one at both endpoints.

FJ has C cows (1 <= C <= 1000) on his farm.  Each cow resides at a point in
the 2D plane that is not on any fence, and no two cows reside at the same
point.  Two cows are said to be in the same community if one could walk to
the other without touching any fences.  Please help FJ determine the size
of the largest community.

PROBLEM NAME: crazy

INPUT FORMAT:

* Line 1: Two space-separated integers N and C.

* Lines 2..1+N: Each line contains four integers: x1, y1, x2, y2,
        indicating a fence from point (x1,y1) to point (x2,y2).  All
        coordinates are integers in the range 0..1,000,000.

* Lines 2+N..1+N+C: Each line contains two integers x and y describing
        the location of a cow.  All coordinates are integers in the
        range 0..1,000,000.

SAMPLE INPUT:

10 4
0 0 10 0
10 0 10 10
0 0 0 10
10 10 0 10
8 8 9 8
9 8 8 9
8 9 8 8
2 7 3 2
3 2 7 5
7 5 2 7
15 3
1 4
4 5
7 1

INPUT DETAILS:

There are 10 fences and 4 cows.  The fences form a square containing two
triangles.

OUTPUT FORMAT:

* Line 1: The number of cows in the largest community.

SAMPLE OUTPUT:

2

OUTPUT DETAILS:

Cows #2 and #4 belong to the same community.  Cows #1 and #3 are each
members of a community of size 1.
