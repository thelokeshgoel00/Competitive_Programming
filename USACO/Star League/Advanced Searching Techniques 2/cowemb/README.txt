Bovine Embroidery
=================

Bessie has taken up the detailed art of bovine embroidery. Cows
embroider a cloth mounted in a circular hoop of integer radius d
(1 <= d <= 50,000). They sew N (2 <= N <= 50,000) threads, each in
a straight line from one point on the edge of the hoop to another
point on the edge of the hoop (no two embroidered points share a
location on the hoop's edge).

Being mathematically inclined, Bessie knows a formula of the form
ax + by + c = 0 for each straight line piece of thread. Conveniently,
a, b, and c are integers (-1,000,000 <= a <= 1,000,000; -1,000,000
<= b <= 1,000,000; -1,000,000 <= c <= 1,000,000). Even more
conveniently, no two threads coincide exactly.

Perhaps less conveniently, Bessie knows that her set of formula
coefficients also includes a number of formulae for threads that
do not appear to pass inside the hoop's circle. She regrets this
greatly.

The origin (0,0) is in the precise middle of the hoop, so all points
on the hoop's edge are distance d from the origin. At least one of
the coefficients a and b is non-zero for each thread's formula.

Bovine embroidery is more highly regarded when the number of thread
intersections is maximized. Help Bessie: count the number of pairs
of threads that intersect on the cloth (i.e., within distance d of
the origin). Note that if three threads happen to coincide at the
same point, that would be three pairs of intersections. Four threads
at the same point -> six pairs of intersections, etc.

PROBLEM NAME: cowemb

INPUT FORMAT:

* Line 1: Two space-separated integers: N and d

* Lines 2..N+1: Line i+1 describes thread i with three integers: a, b,
        and c

SAMPLE INPUT:

2 1
1 0 0
0 1 0

INPUT DETAILS:

The two lines are x=0 and y=0.

OUTPUT FORMAT:

* Line 1: One integer, on a line by itself, that is the count of pairs
        of threads that intersect.

SAMPLE OUTPUT:

1

OUTPUT DETAILS:

The two lines intersect at (0,0), which is clearly with 1 of the origin.
