Treasure Chest
==============

Bessie and Bonnie have found a treasure chest full of marvelous
gold coins! Being cows, though, they can't just walk into a store and
buy stuff, so instead they decide to have some fun with the coins.

The N (1 <= N <= 5,000) coins, each with some value C_i (1 <= C_i
<= 5,000) are placed in a straight line. Bessie and Bonnie take turns,
and for each cow's turn, she takes exactly one coin off of either
the left end or the right end of the line. The game ends when there
are no coins left.

Bessie and Bonnie are each trying to get as much wealth as possible for
themselves. Bessie goes first. Help her figure out the maximum
value she can win, assuming that both cows play optimally.

Consider a game in which four coins are lined up with these values:

            30  25  10  35

Consider this game sequence:

                           Bessie    Bonnie       New Coin
Player   Side   CoinValue   Total     Total         Line
Bessie   Right     35        35         0       30  25  10
Bonnie   Left      30        35        30         25  10
Bessie   Left      25        60        30           10
Bonnie   Right     10        60        40           --

This is the best game Bessie can play.

PROBLEM NAME: treasure

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 contains a single integer: C_i

SAMPLE INPUT:

4
30
25
10
35

OUTPUT FORMAT:

* Line 1: A single integer, which is the greatest total value Bessie
        can win if both cows play optimally.

SAMPLE OUTPUT:

60
