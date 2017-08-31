Cow Neighborhoods
=================

Those Who Know About Cows are aware of the way cows group into "Cow
Neighborhoods". They have observed Farmer John's N (1 <= N <=
100,000) cows (conveniently numbered 1..N) as they graze, each at
her own unique integer rectilinear coordinate, on a pasture whose
X and Y coordinates are in the range 1..1,000,000,000.

Two cows are neighbors if at least one of two criteria is met:

  1) If the cows are no further than integer distance C (1 <= C <=
     1,000,000,000) apart, they are neighbors.

  2) If cow A is a neighbor of cow Z and cow B is a neighbor of cow
     Z, then cow A is a neighbor of cow B.

Given the locations of the cows and the distance C, determine the
number of cows in the largest neighborhood.

By way of example, consider the pasture below. When C = 4, this
pasture has four neighborhoods: a big one on the left, two neighborhoods
of size 1 (the lonesome cows), and a huge neighborhood on the right
with 60 different cows.

.....................................*.................
....*...*..*.......................***.................
......*...........................****.................
..*....*..*.......................*...*.******.*.*.....
........................*.............***...***...*....
*..*..*...*..........................*..*...*..*...*...
.....................................*..*...*..*.......
.....................................*..*...*..*.......
...*................*..................................
.*..*............................*.*.*.*.*.*.*.*.*.*.*.
.*.....*..........................*.*.*.*.*.*.*.*.*.*.*
....*..................................................

In the input file, the cows are described by integer X,Y coordinates,
where the lower left corner is (1,1) and cows close to that corner
appear at both (2,2) and (5,1).
Determine both the number of cow neighborhoods in a given field and
the number of cows resident in the largest cow neighborhood.

PROBLEM NAME: nabor

INPUT FORMAT:

* Line 1: Two space-separated integers: N and C

* Lines 2..N+1: Line i+1 describes cow i's location with two
        space-separated integers: X_i and Y_i

SAMPLE INPUT:

4 2
1 1
2 2
3 3
10 10

OUTPUT FORMAT:

* Line 1: A single line with a two space-separated integers: the
        number of cow neighborhoods, and the size of the largest cow
        neighborhood.

SAMPLE OUTPUT:

2 3

OUTPUT DETAILS:

There are 2 neighborhoods, one formed by the first three cows and the other
being the last cow. The largest neighborhood therefore has size 3.
