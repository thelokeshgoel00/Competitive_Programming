Code Breaking
=============

The cows keep getting in trouble by taking rides on Farmer John's tractor,
so he has hidden the keys to the tractor in a fancy new safe in his 
office. Undeterred, the cows have vowed to try and break into this safe.

The safe is protected by a rather complicated passcode system. The passcode
entry system is arranged as a rooted tree of N (1 <= N <= 20,000) nodes,
each of which requires a digit between 0 and 9. The nodes are indexed 0..N-1.

The only information that the cows have is that certain sequences of length
5 do not occur along particular paths upwards through the tree.

For instance, suppose the tree is the following (rooted at A):

A <- B <- C <- D <- E
               ^
               |
               F

The cows might know that the sequence 01234 does not occur starting at F, 
and that the sequence 91234 does not occur starting at E. This information 
rules out 19 possible passcodes: all those of the form

4 <- 3 <- 2 <- 1 <- *
               ^
               |
               0

or

4 <- 3 <- 2 <- 1 <- 9
               ^
               |
               *

which gives 19 once we account for the fact that 

4 <- 3 <- 2 <- 1 <- 9
               ^
               |
               0

appears twice.

Given M (1 <= M <= 50,000) length-5 sequences, together with their starting
nodes in the tree, help the cows figure out how many passcodes have been
ruled out. You should compute your answer modulo 1234567.

PROBLEM NAME: code

INPUT FORMAT:

* Line 1: Two space-separated integers, N and M.

* Lines 2..N: Line i+1 contains a single integer p(i), denoting the
        parent of node i in the tree (0 <= p(i) < i).

* Lines N+1..N+M: Line N+i describes the ith sequence known not to
        occur in the code.  The line will contain v(i) and s(i)
        separated by a space, where v(i) is the starting node of the
        sequence, and s(i) is a 5-digit string known not to occur
        starting at v(i) and proceeding upward in the tree.  It is
        guaranteed that the root is at least 4 steps upward from v(i).

SAMPLE INPUT:

6 2
0
1
2
3
3
4 01234
5 91234

OUTPUT FORMAT:

* Line 1: A single integer giving the number of ruled-out
        configurations, modulo 1234567.

SAMPLE OUTPUT:

19
