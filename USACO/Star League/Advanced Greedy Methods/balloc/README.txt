Barn Allocation
===============

Farmer John recently opened up a new barn and is now accepting stall
allocation requests from the cows since some of the stalls have a
better view of the pastures.

The barn comprises N (1 <= N <= 100,000) stalls conveniently numbered
1..N; stall i has capacity C_i cows (1 <= C_i <= 100,000). Cow i
may request a contiguous interval of stalls (A_i, B_i) in which to
roam (1 <= A_i <= N; A_i <= B_i <= N), i.e., the cow would like to
wander among all the stalls in the range A_i..B_i (and the stalls
must always have the capacity for her to wander).

Given M (1 <= M <= 100,000) stall requests, determine the maximum
number of them that can be satisfied without exceeding stall
capacities.

Consider both a barn with 5 stalls that have the capacities shown
and a set cow requests:

Stall id:    1   2   3   4   5
           +---+---+---+---+---+
Capacity:  | 1 | 3 | 2 | 1 | 3 |  
           +---+---+---+---+---+
Cow 1       XXXXXXXXXXX             (1, 3)
Cow 2           XXXXXXXXXXXXXXX     (2, 5)
Cow 3           XXXXXXX             (2, 3)
Cow 4                   XXXXXXX     (4, 5)

FJ can't satisfy all four cows, since there are too many requests
for stalls 3 and 4.

Noting that Cow 2 requests an interval that includes stalls 3 and
4, we test the hypothesis that cows 1, 3, and 4 can have their
requested stalls. No capacity is exceeded, so the answer for this
set of data is 3 -- three cows (1, 3, and 4) can have their requests
satisfied.

PROBLEM NAME: balloc

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M
* Lines 2..N+1: Line i+1 contains a single integer: C_i
* Lines N+2..N+M+1: Line i+N+1 contains two integers: A_i and B_i

SAMPLE INPUT:

5 4
1
3
2
1
3
1 3
2 5
2 3
4 5

OUTPUT FORMAT:

* Line 1: The maximum number of requests that can be satisfied

SAMPLE OUTPUT:

3
