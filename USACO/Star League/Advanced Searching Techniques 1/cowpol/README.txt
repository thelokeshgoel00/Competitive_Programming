Cow Politics
============

Farmer John's cows are living on N (2 <= N <= 200,000) different
pastures conveniently numbered 1..N. Exactly N-1 bidirectional cow
paths (of unit length) connect these pastures in various ways, and
each pasture is reachable from any other cow pasture by traversing
one or more of these paths (thus, the pastures and paths form a
graph called a tree).

The input for a particular set of pastures will specify the parent
node P_i (0 <= P_i <= N) for each pasture. The root node will specify
parent P_i == 0, which means it has no parent.

The cows have organized K (1 <= K <= N/2) different political parties
conveniently numbered 1..K. Each cow identifies with a single
political party; cow i identifies with political party A_i (1 <=
A_i <= K). Each political party includes at least two cows.

The political parties are feuding and would like to know how much
'range' each party covers. The range of a party is the largest
distance between any two cows within that party (over cow paths).

For example, suppose political party 1 consists of cows 1, 3, and
6, political party 2 consists of cows 2, 4, and 5, and the pastures
are connected as follows (party 1 members are marked as -n-):

  -3-
   |
  -1-
 / | \
2  4  5
      |
     -6-

The greatest distance between any two pastures of political party
1 is 3 (between cows 3 and 6), and the greatest distance for political
party 2 is 2 (between cows 2 and 4, between cows 4 and 5, and between
cows 5 and 2).

Help the cows determine party ranges.

PROBLEM NAME: cowpol

INPUT FORMAT:

* Line 1: Two space-separated integers: N and K

* Lines 2..N+1: Line i+1 contains two space-separated integers: A_i
        and P_i

SAMPLE INPUT:

6 2
1 3
2 1
1 0
2 1
2 1
1 5

OUTPUT FORMAT:

* Lines 1..K: Line i contains a single integer that is the range of
        party i.

SAMPLE OUTPUT:

3
2
