Game of Lines
=============

Farmer John has challenged Bessie to the following game: FJ has a
board with dots marked at N (2 <= N <= 200) distinct lattice points.
Dot i has the integer coordinates X_i and Y_i (-1,000 <= X_i <=
1,000; -1,000 <= Y_i <= 1,000).

Bessie can score a point in the game by picking two of the dots and
drawing a straight line between them; however, she is not allowed
to draw a line if she has already drawn another line that is parallel
to that line. Bessie would like to know her chances of winning, so
she has asked you to help find the maximum score she can obtain.

PROBLEM NAME: lines

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 describes lattice point i with two
        space-separated integers: X_i and Y_i.

SAMPLE INPUT:

4
-1 1
-2 0
0 0
1 1

OUTPUT FORMAT:

* Line 1: A single integer representing the maximal number of lines
        Bessie can draw, no two of which are parallel.

SAMPLE OUTPUT:

4

OUTPUT DETAILS:

Bessie can draw lines of the following four slopes: -1, 0, 1/3, and 1.
