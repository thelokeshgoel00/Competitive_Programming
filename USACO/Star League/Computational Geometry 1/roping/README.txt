Roping the Field
================

Farmer John is quite the nature artist: he often constructs large
works of art on his farm. Today, FJ wants to construct a giant
"field web". FJ's field is large convex polygon with fences along
the boundary and fence posts at each of the N corners (1 <= N <=
150). To construct his field web, FJ wants to run as many ropes as
possible in straight lines between pairs of non-adjacent fence posts
such that no two ropes cross.

There is one complication: FJ's field is not completely usable.
Some evil aliens have created a total of G (0 <= G <= 100) grain
circles in the field, all of radius R (1 <= R <= 100,000). FJ is
afraid to upset the aliens, and therefore doesn't want the ropes
to pass through, or even touch the very edge of a grain circle.
Note that although the centers of all the circles are contained
within the field, a wide radius may make it extend outside of the
field, and both fences and fence posts may be within a grain circle.

Given the locations of the fence posts and the centers of the
circles, determine the maximum number of ropes that FJ can use to
create his field web.

FJ's fence posts and the circle centers all have integer coordinates
X and Y each of which is in the range 0..1,000,000.

PROBLEM NAME: roping

INPUT FORMAT:

* Line 1: Three space-separated integers: N, G, and R

* Lines 2..N+1: Each line contains two space-separated integers that
        are the X,Y position of a fence post on the boundary of FJ's
        field.

* Lines N+2..N+G+1: Each line contains two space-separated integers
        that are the X,Y position of a circle's center inside FJ's
        field.

SAMPLE INPUT:

5 3 1
6 10
10 7
9 1
2 0
0 3
2 2
5 6
8 3

INPUT DETAILS:

A pentagonal field, in which all possible ropes are blocked by three
grain circles, except for the rope between fenceposts 2 and 4.

OUTPUT FORMAT:

* Line 1: A single integer that is the largest number of ropes FJ can
        use for his artistic creation.

SAMPLE OUTPUT:

1
