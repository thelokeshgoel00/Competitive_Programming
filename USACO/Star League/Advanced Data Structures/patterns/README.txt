Milk Patterns
=============

Farmer John has noticed that the quality of milk given by his cows
varies from day to day. On further investigation, he discovered
that although he can't predict the quality of milk from one day to
the next, there are some regular patterns in the daily milk quality.

To perform a rigorous study, he has invented a complex classification
scheme by which each milk sample is recorded as an integer between
0 and 1,000,000 inclusive, and has recorded data from a single cow
over N (1 <= N <= 20,000) days. He wishes to find the longest
pattern of samples which repeats identically at least K (2 <= K <= N) times.
This may include overlapping patterns -- 1 2 3 2 3 2 3 1 repeats 2
3 2 3 twice, for example.

Help Farmer John by finding the longest repeating subsequence in
the sequence of samples. It is guaranteed that at least one subsequence
is repeated at least K times.

PROBLEM NAME: patterns

INPUT FORMAT:

* Line 1: Two space-separated integers: N and K

* Lines 2..N+1: N integers, one per line, the quality of the milk on
        day i appears on the ith line.

SAMPLE INPUT (file patterns.in):

8 2
1
2
3
2
3
2
3
1


OUTPUT FORMAT:

* Line 1: One integer, the length of the longest pattern which occurs
        at least K times

SAMPLE OUTPUT (file patterns.out):

4
