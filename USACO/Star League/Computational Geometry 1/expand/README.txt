Barn Expansion
==============

Farmer John has N (1 <= N <= 25,000) rectangular barns on his farm, all
with sides parallel to the X and Y axes and integer corner coordinates in
the range 0..1,000,000. These barns do not overlap although they may
share corners and/or sides with other barns.

Since he has extra cows to milk this year, FJ would like to expand some of
his barns.  A barn has room to expand if it does not share a corner or a
wall with any other barn.  That is, FJ can expand a barn if all four of its
walls can be pushed outward by at least some amount without bumping into
another barn.  If two barns meet at a corner, neither barn can expand.

Please determine how many barns have room to expand.

PROBLEM NAME: expand

INPUT FORMAT:

* Line 1: A single integer, N

* Lines 2..N+1: Four space-separated integers A, B, C, and D,
        describing one barn. The lower-left corner of the barn is at
        (A,B) and the upper right corner is at (C,D).

SAMPLE INPUT:

5
0 2 2 7
3 5 5 8
4 2 6 4
6 1 8 6
0 0 8 1

INPUT DETAILS:

There are 5 barns.  The first barn has its lower-left corner at (0,2) and
its upper-right corner at (2,7), and so on.

OUTPUT FORMAT:

* Line 1: A single integer that is the number of barns that can be
        expanded.

SAMPLE OUTPUT:

2

OUTPUT DETAILS:

Only two barns can be expanded --- the first two listed in the input.
All other barns are each in contact with at least one other barn.
