The Baric Bovine
================

Following up on a journal article about increasing milk production,
Bessie has become the Baric Bovine by studying atmospheric pressure
in order to curry favor with Farmer John.
She takes N (1 <= N <= 100) measurements conveniently named M_1
through M_N during the day (1 <= M_i <= 1,000,000); these measurements
are numbered are in the order in which Bessie observed them.

In order to characterize the day's atmospheric pressure readings,
she is interested in finding a subset of the measurements (given
by the K (1 <= K <= N) indices s_j where 1 <= s_1 < s_2 < ... < s_K
<= N) that accurately reflects the entire set, i.e., limits the
error as described below.
In any subset of measurements, an error is incurred for each
measurement (1) before the first member of the subset, (2) between
two consecutive measurements in the subset, and (3) after the last
member of the subset. The total error value for a given set of s_j
values is the sum of each of the individual errors.

Specifically, for all measurements whose index i is not one of the
s_j values:

* if i is less than s_1, then the sample error is:
             2 * | M_i - M_(s_1) | 
* if i is between s_j and s_(j+1), then the sample error is
            | 2 * M_i - Sum(s_j, s_(j+1)) |  
  where Sum(x, y) = M_x + M_y;
* if i is greater than s_K, then the sample error is
             2 * | M_i - M_(s_K) |

Given a maximum error value E (1 <= E <= 1,000,000), determine the
size of the smallest subset of measurements that produces an error
of at most E.

PROBLEM NAME: baric

INPUT FORMAT:

* Line 1: Two space-separated integers: N and E

* Lines 2..N+1: Line i+1 contains a single measurement: M_i

SAMPLE INPUT:

4 20
10
3
20
40

INPUT DETAILS:

Bessie takes four measurements; the maximum error is 20. The
measurements are, in sequence: 10, 3, 20, and 40.

OUTPUT FORMAT:

* Line 1: Two space-separated integers: the size of the smallest
        subset of measurements that produces an error of at most E and
        the corresponding error of the subset.

SAMPLE OUTPUT:

2 17

OUTPUT DETAILS:

Choosing the second and fourth measurements is the best option,
giving an error of 17. The first term's error is 2*|10-3| = 14; the
third term's error is |2*20 - (3+40)| = 3.
