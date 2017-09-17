Ski Lift
========

Farmer Ron in Colorado is building a ski resort for his cows (though
budget constraints dictate construction of just one ski lift). The
lift will be constructed as a monorail and will connect a concrete
support at the starting location to the support at the ending
location via some number of intermediate supports, each of height
0 above its land. A straight-line segment of steel connects every
pair of adjacent supports. For obvious reasons, each section of
straight steel must lie above the ground at all points.

Always frugal, FR wants to minimize the number of supports that he
must build. He has surveyed the N (2 <= N <= 5,000) equal-sized
plots of land the lift will traverse and recorded the integral
height H (0 <= H <= 1,000,000,000) of each plot. Safety regulations
require FR to build adjacent supports no more than K (1 <= K <= N
- 1) units apart. The steel between each pair of supports is rigid
and forms a straight line from one support to the next.

Help FR compute the smallest number of supports required such that:
each segment of steel lies entirely above (or just tangent to) each
piece of ground, no two consecutive supports are more than K units
apart horizontally, and a support resides both on the first plot
of land and on the last plot of land.

PROBLEM NAME: skilift

INPUT FORMAT:

* Line 1: Two space-separate integers, N and K

* Lines 2..N+1: Line i+1 contains a single integer that is the height
        of plot i.

SAMPLE INPUT:

13 4
0
1
0
2
4
6
8
6
8
8
9
11
12

OUTPUT FORMAT:

* Line 1: A single integer equal to the fewest number of lift towers
        FR needs to build subject to the above constraints

SAMPLE OUTPUT:
5

OUTPUT DETAILS:

FR builds five supports (at locations 1, 5, 7, 9, and 13). The steel
is tangent to the ground at four locations: 1-5, 5-7, 7-9, and
12-13.

If FR only builds supports at the four locations 1, 5, 9, and 13,
then the steel would be below ground from 5-9. If FR built supports
at 1, 7, and 13, then -- although the steel is always above ground
-- supports 7 and 13 are more than 4 units apart horizontally. There
is no solution using fewer than 5 supports such that no two consecutive
supports are more than 4 units apart horizontally.
