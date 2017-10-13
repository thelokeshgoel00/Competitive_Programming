Gourmet Grazers
===============

Like so many others, the cows have developed very haughty tastes
and will no longer graze on just any grass. Instead, Farmer John
must purchase gourmet organic grass at the Green Grass Grocers store
for each of his N (1 <= N <= 100,000) cows.

Each cow_i demands grass of price at least A_i (1 <= A_i <=
1,000,000,000) and with a greenness score at least B_i (1 <= B_i
<= 1,000,000,000). The GGG store has M (1 <= M <= 100,000) different
types of grass available, each with a price C_i (1 <= C_i <=
1,000,000,000) and a greenness score of D_i (1 <= D_i <= 1,000,000,000).
Of course, no cow would sacrifice her individuality, so no two cows
can have the same kind of grass.

Help Farmer John satisfy the cows' expensive gourmet tastes while
spending as little money as is necessary.

PROBLEM NAME: gourmet

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M.

* Lines 2..N+1: Line i+1 contains two space-separated integers: A_i
        and B_i

* Lines N+2..N+M+1: Line i+N+1 contains two space-separated integers:
        C_i and D_i

SAMPLE INPUT (file gourmet.in):

4 7
1 1
2 3
1 4
4 2
3 2
2 1
4 3
5 2
5 4
2 6
4 4

OUTPUT FORMAT:

* Line 1: A single integer which is the minimum cost to satisfy all
        the cows. If that is not possible, output -1.

SAMPLE OUTPUT (file gourmet.out):

12

OUTPUT DETAILS:

Cow 1 eats grass 2 at cost 2, cow 2 eats grass 3 at cost 4, cow 3 eats
grass 6 at cost 2, and cow 4 eats grass 7 at cost 4, for a total cost of 12.
