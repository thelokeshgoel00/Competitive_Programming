Mowing the Lawn
===============

After winning the annual town competition for best lawn a year ago,
Farmer John has grown lazy; he has not mowed the lawn since then
and thus his lawn has become unruly. However, the competition is
once again coming soon, and FJ would like to get his lawn into
tiptop shape so that he can claim the title.

Unfortunately, FJ has realized that his lawn is so unkempt that he
will need to get some of his N (1 <= N <= 100,000) cows, who are
lined up in a row and conveniently numbered 1..N, to help him. Some
cows are more efficient than others at mowing the lawn; cow i has
efficiency E_i (0 <= E_i <= 1,000,000,000).

FJ has noticed that cows near each other in line often know each
other well; he has also discovered that if he chooses more than K
(1 <= K <= N) consecutive (adjacent) cows to help him, they will
ignore the lawn and start a party instead. Thus, FJ needs you to
assist him: determine the largest total cow efficiency FJ can obtain
without choosing more than K consecutive cows.

PROBLEM NAME: mowlawn

INPUT FORMAT:

* Line 1: Two space-separated integers: N and K

* Lines 2..N+1: Line i+1 contains the single integer: E_i

SAMPLE INPUT:

5 2
1
2
3
4
5

INPUT DETAILS:

FJ has 5 cows whose efficiencies are 1, 2, 3, 4, and 5, in that
order. He wants to choose some of the cows such that their total
efficiency is maximized, but he cannot choose more than 2 consecutive
cows.

OUTPUT FORMAT:

* Line 1: A single integer that is the best total efficiency FJ can
        obtain.

SAMPLE OUTPUT:

12

OUTPUT DETAILS:

FJ chooses all cows but the third. The total efficiency of the cows is thus
1 + 2 + 4 + 5 = 12.
