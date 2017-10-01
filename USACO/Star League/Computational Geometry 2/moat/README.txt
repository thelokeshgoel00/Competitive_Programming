Building the Moat
=================

To repel the invading thirsty aardvarks, Farmer John wants to build
a moat around his farm.  He owns N (8 <= N <= 5,000) watering holes,
and will be digging the moat in a straight line between pairs of
them.  His moat should protect (i.e., surround) all his watering
holes; every watering hole must be on or inside the moat, and the
moat must form a closed loop.

Digging a moat is expensive work, and frugal FJ wants his moat to
have the minimum length possible.  Find the length of the shortest
moat he can construct.

The unique holes are each located at integer coordinates in the
range (1..45,000, 1..45,000). FJ has noticed that no three
watering holes lie along the same line.

Consider this grid where the 20 '*'s represent watering holes:

...*-----------------*......
../..........*........\.....
./.....................\....
*......................*\...
|..........*........*....\..
|*........................\.
|..........................*
*..........................|
.\*........................|
..\.....................*..|
...\........*............*.|
....\..................*...*
.....\..*..........*....../.
......\................../..
.......*----------------*...

The enclosing lines are the shortest possible path that can enclose
this set of watering holes.

The line displacements, starting with the top line are: (18,0),
(6,-6), (0,-5), (-3,-3), (-17,0), (-7,7), (0,4), and (3,3).  This
yields a distance of 70.8700576850888(...). Our output will print
only two decimal places, so the distance will be reported as 70.87.

PROBLEM NAME: moat

INPUT FORMAT:

* Line 1: A single integer, N

* Lines 2..N+1: Two space-separated integers, X_i and Y_i that specify
        the location of a watering hole.

SAMPLE INPUT:

20
2 10
3 7
22 15
12 11
20 3
28 9
1 12
9 3
14 14
25 6
8 1
25 1
28 4
24 12
4 15
13 5
26 5
21 11
24 4
1 8


OUTPUT FORMAT:

* Line 1: A single number D, the shortest possible length of moat.
        Print this number to two decimal places.

SAMPLE OUTPUT:

70.87
