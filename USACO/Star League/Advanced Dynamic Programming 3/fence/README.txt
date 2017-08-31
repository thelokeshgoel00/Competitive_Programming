Largest Fence
=============

Farmer John has purchased N (5 <= N <= 250) fence posts in order
to build a very nice-looking fence. Everyone knows the best fences
are convex polygons where fence posts form vertices of a polygon.
The pasture is represented as a rectilinear grid; fencepost i is
at integer coordinates (x_i, y_i) (1 <= x_i <= 1,000; 1 <= y_i <=
1000).

Given the locations of N fence posts (which, intriguingly, feature
no set of three points which are collinear), what is the largest
number of fence posts FJ can use to create a fence that is convex?

For test cases worth 45% of the points for this problem, N <= 65.

PROBLEM NAME: fence

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 describes fence post i's location with two
        space-separated integers: x_i and y_i

SAMPLE INPUT:

6
5 5
2 3
3 2
1 5
5 1
1 1

INPUT DETAILS:

A square with two points inside.

OUTPUT FORMAT:

* Line 1: A single integer, the maximum possible number of fence 
        posts that form a convex polygon.

SAMPLE OUTPUT:

5

OUTPUT DETAILS:

The largest convex polygon is the pentagon (2,3), (3,2), (5,1), 
(5,5), (1,5).
