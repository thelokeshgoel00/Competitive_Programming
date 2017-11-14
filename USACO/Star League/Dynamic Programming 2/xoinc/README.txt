A Coin Game
===========

Farmer John's cows like to play coin games so FJ has invented with
a new two-player coin game called Xoinc for them.

Initially a stack of N (5 <= N <= 2,000) coins sits on the ground;
coin i from the top has integer value C_i (1 <= C_i <= 100,000).

The first player starts the game by taking the top one or two coins
(C_1 and maybe C_2) from the stack. If the first player takes just
the top coin, the second player may take the following one or two
coins in the next turn. If the first player takes two coins then
the second player may take the top one, two, three or four coins
from the stack. In each turn, the current player must take at least
one coin and at most two times the amount of coins last taken by
the opposing player. The game is over when there are no more coins
to take.

Afterwards, they can use the value of the coins they have taken
from the stack to buy treats from FJ, so naturally, their purpose
in the game is to maximize the total value of the coins they take.
Assuming the second player plays optimally to maximize his own
winnings, what is the highest total value that the first player can
have when the game is over?

PROBLEM NAME: xoinc

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 contains a single integer: C_i

SAMPLE INPUT:

5
1
3
1
7
2

INPUT DETAILS:

There are five coins with the values 1, 3, 1, 7, and 2.

OUTPUT FORMAT:

* Line 1: A single integer representing the maximum value that can be
        made by the first player.

SAMPLE OUTPUT:

9

OUTPUT DETAILS:

The first player starts by taking a single coin (value 1). The
opponent takes one coin as well (value 3). The first player takes
two more coins (values 1 and 7 -- total 9). The second player gets
the leftover coin (value 2-- total 5).
