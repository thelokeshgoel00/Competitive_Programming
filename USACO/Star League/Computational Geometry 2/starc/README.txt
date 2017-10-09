StarCowraft
===========

The beta version of StarCowraft II is ready! Farmer John and Bessie
are testing it, trying different strategies in one-on-one battles
against each other's armies. The goal in StarCowraft II is to defeat
your opponent's army in a battle.

Each player's army fights in a battle. An army comprises as many
as three different types of 'units' with respective strengths denoted
by constant positive real numbers unknown to the players: cattlebruisers
with strength S1, cow templars with strength S2, and ultracows with
strength S3. The only given bounding information is that no unit
is more than 100 times as strong as any another unit.

An army's total strength is the sum of the individual strengths of
each of its units. An army that has, among others units, 23
cattlebruisers would gain 23*S1 strength just from the cattlebruisers.

When two opposing armies fight in a battle, the army with a higher
total strength value wins.  If the armies have exactly equal strength
values, one of the players randomly wins.

Farmer John and Bessie played N (0 <= N <= 300) "test battles". In
the i-th test battle, FJ's army had J1_i cattlebruisers, J2_i cow
templars, and J3_i ultracows (0 <= J1_i + J2_i + J3_i <= 1,000).
Similarly, Bessie's army had B1_i cattlebruisers, B2_i cow templars,
and B3_i ultracows (0 <= B1_i + B2_i + B3_i <= 1,000). After their
armies fought against each other, FJ and Bessie recorded the winner
as a single 'victory letter' V_i: "J" if Farm John won the battle;
"B" if Bessie won.

Although these victory results are the only information that they
have, they hope to predict some of the results of additional battles
if they are given the unit compositions of two opposing armies. For
some battles, though, they know it might not be possible to determine
the winner with certainty.

Given the results of the N test battles that Farmer John and Bessie
already played, write a program that decides the winner (if possible)
for M (1 <= M <= 2,000) new battles.

The results reported for the test battles are correct; there exists
at least one set of strength values which are consistent with the
results.

For purposes of demonstrating the army strength evaluation functions,
consider these test battles fought in a game where we (but neither
FJ nor Bessie) know that S1=9.0, S2=7.0, and S3=4.0:

   ---- Farmer John ----    ------- Bessie ------    Battle
   J1  J2  J3 J_Strength    B1  B2  B3 B_Strength   Outcome
    6   5   4    105         5   4   7    101          J
    5   4   2     81         3   5   5     82          B
    9   0  10    121         8   2   7    114          J

These results connote the following deduced results for the reasons
shown:

   ---- Farmer John ----    ------- Bessie ------    Battle
   J1  J2  J3 J_Strength    B1  B2  B3 B_Strength   Outcome
    6   6   4    112         5   4   7    101          J
              FJ's army is even stronger than in test battle 1
    9   0  10    121         8   2   6    110          J
              Bessie's army is even weaker than in test battle 3

PROBLEM NAME: starc

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M

* Lines 2..N+1: Line i+1 describes a test battle with seven
        space-separated items -- a victory letter and six
        space-separated integer unit counts: V_i, J1_i, J2_i, J3_i,
        B1_i, B2_i, and B3_i

* Lines N+2..N+M+1: Line i+N+1 describes a "new battle" using six
        space-separated integers: J1_i, J2_i, J3_i, B1_i, B2_i, and
        B3_i

SAMPLE INPUT:

3 3
J 6 5 4 5 4 7
B 5 4 2 3 5 5
J 9 0 10 8 2 7
6 6 4 5 4 7
9 0 10 8 2 6
3 4 8 4 4 6

OUTPUT FORMAT:

* Lines 1..M: Line i contains the outcome of the i-th new battle: "J"
        if Farmer John definitely wins, "B" if Bessie definitely wins,
        and "U" (undecidable) if it is impossible to decide the winner
        with the given information.

SAMPLE OUTPUT:

J
J
U

OUTPUT DETAILS:

First two games correspond to the examples in the description. The
result of the last game cannot be determined with only the information
that Farmer John and Bessie currently have. Specifically, both S_1=9.0, 
S_2=7.0, S_3=4.0 and S_1=12.0, S_2=20.0, S_3=10.0 are consistent with the 
"test battles," but they give different results when plugged in the third 
"new battle."
