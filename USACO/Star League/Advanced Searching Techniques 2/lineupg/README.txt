Balanced Lineup
===============

For the daily milking, Farmer John's N cows (1 <= N <= 50,000)
always line up in the same order. One day Farmer John decides to
organize a game of Ultimate Frisbee with some of the cows. To keep
things simple, he will take a contiguous range of cows from the
milking lineup to play the game. However, for all the cows to have
fun, they should not differ too much in height.

Farmer John has made a list of Q (1 <= Q <= 180,000) potential
groups of cows and their heights (1 <= height <= 1,000,000). For
each group, he wants your help to determine the difference in height
between the shortest and the tallest cow in the group.

Note: on the largest test case, I/O takes up the majority of the
runtime.

PROBLEM NAME: lineupg

INPUT FORMAT:

* Line 1: Two space-separated integers, N and Q.

* Lines 2..N+1: Line i+1 contains a single integer that is the height
        of cow i

* Lines N+2..N+Q+1: Two integers A and B (1 <= A <= B <= N),
        representing the range of cows from A to B inclusive.

SAMPLE INPUT:

6 3
1
7
3
4
2
5
1 5
4 6
2 2


OUTPUT FORMAT:

* Lines 1..Q: Each line contains a single integer that is an answer to
        an input query and tells the difference in height between the
        tallest and shortest cow in the input range.

SAMPLE OUTPUT:

6
3
0
