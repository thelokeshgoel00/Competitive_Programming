Building A New Barn
===================

After scrimping and saving for years, Farmer John has decided to
build a new barn. He wants the barn to be highly accessible, and
he knows the coordinates of the grazing spots of all N (2 <= N <=
10,000) cows. Each grazing spot is at a point with integer coordinates
(X_i, Y_i) (-10,000 <= X_i <= 10,000; -10,000 <= Y_i <= 10,000).
The hungry cows never graze in spots that are horizontally or
vertically adjacent.

The barn must be placed at integer coordinates and cannot be on any
cow's grazing spot. The inconvenience of the barn for any cow is
given the Manhattan distance formula |X-X_i|+|Y-Y_i|, where (X, Y)
and (X_i, Y_i) are the coordinates of the barn and the cow's grazing
spot, respectively.  Where should the barn be constructed in order
to minimize the sum of its inconvenience for all the cows?

PROBLEM NAME: newbarn

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 contains two space-separated integers which
        are the grazing location (X_i, Y_i) of cow i

SAMPLE INPUT:

4
1 -3
0 1
-2 1
1 -1

INPUT DETAILS:

The field contains 4 cows with grazing spots at the points (1, -3),
(0, 1), (-2, 1), and (1, -1).

OUTPUT FORMAT:

* Line 1: Two space-separated integers: the minimum inconvenience for
        the barn and the number of spots on which Farmer John can
        build the barn to achieve this minimum.

SAMPLE OUTPUT:

10 4

OUTPUT DETAILS:

The minimum inconvenience is 10, and there are 4 spots that Farmer John can
build the farm to achieve this: (0, -1), (0, 0), (1, 0), and (1, 1).
