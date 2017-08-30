Cow Calisthenics
================

Farmer John continues his never-ending quest to keep the cows fit
by having them exercise on various cow paths that run through the
pastures. These cow paths can be represented as a set of vertices
connected with bidirectional edges so that each pair of vertices
has exactly one simple path between them. In the abstract, their
layout bears a remarkable resemblance to a tree. Surprisingly, each
edge (as it winds its way through the pastures) has the same length.

For any given set of cow paths, the canny cows calculate the longest
possible distance between any pair of vertices on the set of cowpaths
and call it the pathlength. If they think this pathlength is too
large, they simply refuse to exercise at all.

Farmer John has mapped the paths and found V (2 <= V <= 100,000)
vertices, conveniently numbered from 1..V. In order to make shorter
cowpaths, he can block the path between any two vertices, thus
creating more sets of cow paths while reducing the pathlength of
both cowpath sets.

Starting from a single completely connected set of paths (which
have the properties of a tree), FJ can block S (1 <= S <= V-1)
paths, creating S+1 sets of paths. Your goal is to compute the best
paths he can create so that the largest pathlength of all those
sets is minimized.

Farmer John has a list of all V-1 edges in his tree, each described
by the two vertices A_i (1 <= A_i <= V) and B_i (1 <= B_i <= V; A_i
!= B_i) that it connects.

Consider this rather linear cowpath set (a tree with 7 vertices):
                   1---2---3---4---5---6---7

If FJ can block two paths, he might choose them to make a map like
this:
		   1---2 | 3---4 | 5---6---7

where the longest pathlength is 2, which would be the answer in
this case. He can do no better than this.

PROBLEM NAME: exercise

INPUT FORMAT:

* Line 1: Two space separated integers: V and S

* Lines 2..V: Two space separated integers: A_i and B_i

SAMPLE INPUT:

7 2
6 7
3 4
6 5
1 2
3 2
4 5

OUTPUT FORMAT:

* Line 1: A single integer that is the best maximum pathlength FJ can
        achieve with S blocks

SAMPLE OUTPUT:

2
