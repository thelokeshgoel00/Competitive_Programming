Corral the Cows
===============

Farmer John wishes to build a corral for his cows. Being finicky
beasts, they demand that the corral be square and that the corral
contain at least C (1 <= C <= 500) clover fields for afternoon
treats. The corral's edges must be parallel to the X,Y axes. 

FJ's land contains a total of N (C <= N <= 500) clover fields, each
a block of size 1 x 1 and located at with its lower left corner at
integer X and Y coordinates each in the range 1..10,000. Sometimes
more than one clover field grows at the same location; such a field
would have its location appear twice (or more) in the input. A
corral surrounds a clover field if the field is entirely located
inside the corral's borders.

Help FJ by telling him the side length of the smallest square
containing C clover fields.

PROBLEM NAME: corral

INPUT FORMAT:

* Line 1: Two space-separated integers: C and N

* Lines 2..N+1: Each line contains two space-separated integers that
        are the X,Y coordinates of a clover field.

SAMPLE INPUT:

3 4
1 2
2 1
4 1
5 2

INPUT DETAILS:

|*   *
| * *
+------

OUTPUT FORMAT:

* Line 1: A single line with a single integer that is length of one
        edge of the minimum size square that contains at least C
        clover fields.

SAMPLE OUTPUT:

4

OUTPUT DETAILS:

Below is one 4x4 solution (C's show most of the corral's area); many
others exist.

|CCCC
|CCCC
|*CCC*
|C*C*
+------
