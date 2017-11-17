Gold Balanced Lineup
====================

Farmer John's N cows (1 <= N <= 100,000) share many similarities.
In fact, FJ has been able to narrow down the list of features shared
by his cows to a list of only K different features (1 <= K <= 30).
For example, cows exhibiting feature #1 might have spots, cows
exhibiting feature #2 might prefer C to Pascal, and so on.

FJ has even devised a concise way to describe each cow in terms of
its "feature ID", a single K-bit integer whose binary representation
tells us the set of features exhibited by the cow. As an example,
suppose a cow has feature ID = 13. Since 13 written in binary is
1101, this means our cow exhibits features 1, 3, and 4 (reading
right to left), but not feature 2. More generally, we find a 1 in
the 2^(i-1) place if a cow exhibits feature i.

Always the sensitive fellow, FJ lined up cows 1..N in a long row
and noticed that certain ranges of cows are somewhat "balanced" in
terms of the features the exhibit. A contiguous range of cows i..j
is balanced if each of the K possible features is exhibited by the
same number of cows in the range. FJ is curious as to the size of
the largest balanced range of cows. See if you can determine it.

PROBLEM NAME: lineup2

INPUT FORMAT:

* Line 1: Two space-separated integers, N and K.

* Lines 2..N+1: Line i+1 contains a single K-bit integer specifying
       the features present in cow i.  The least-significant bit of
       this integer is 1 if the cow exhibits feature #1, and the
       most-significant bit is 1 if the cow exhibits feature #K.

SAMPLE INPUT:

7 3
7
6
7
2
1
4
2

INPUT DETAILS:

The line has 7 cows with 3 features; the table below summarizes the
correspondence:
             Feature 3:   1   1   1   0   0   1   0
             Feature 2:   1   1   1   1   0   0   1
             Feature 1:   1   0   1   0   1   0   0
             Key:         7   6   7   2   1   4   2
             Cow #:       1   2   3   4   5   6   7

OUTPUT FORMAT:

* Line 1: A single integer giving the size of the largest contiguous
       balanced group of cows.

SAMPLE OUTPUT:

4

OUTPUT DETAILS:

In the range from cow #3 to cow #6 (of size 4), each feature appears
in exactly 2 cows in this range:
             Feature 3:     1   0   0   1  -> two total
             Feature 2:     1   1   0   0  -> two total
             Feature 1:     1   0   1   0  -> two total
             Key:           7   2   1   4
             Cow #:         3   4   5   6
