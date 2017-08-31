The Fewest Coins
================

Farmer John has gone to town to buy some farm supplies. Being a
very efficient man, he always pays for his goods in such a way that
the smallest number of coins changes hands, i.e., the number of
coins he uses to pay plus the number of coins he receives in change
is minimized. Help him to determine what this minimum number is.

FJ wants to buy T (1 <= T <= 10,000) cents of supplies.  The currency
system has N (1 <= N <= 100) different coins, with values V1, V2,
..., VN (1 <= Vi <= 120). Farmer John is carrying C1 coins of value
V1, C2 coins of value V2, ...., and CN coins of value VN (0 <= Ci
<= 10,000). The shopkeeper has an unlimited supply of all the coins,
and always makes change in the most efficient manner (although
Farmer John must be sure to pay in a way that makes it possible to
make the correct change).

PROBLEM NAME: fewcoins

INPUT FORMAT:

* Line 1: Two space-separated integers: N and T.

* Line 2: N space-separated integers, respectively V1, V2, ..., VN
        coins (V1...VN).

* Line 3: N space-separated integers, respectively C1, C2, ..., CN

SAMPLE INPUT:

3 70
5 25 50
5 2 1


INPUT DETAILS:

Farmer John has 5x5 cent coins, 2x25 cent coins and 1x50 cent coin.
His bill is 70 cents.

OUTPUT FORMAT:

* Line 1: A line containing a single integer, the minimum number of
        coins involved in a payment and change-making. If it is
        impossible for Farmer John to pay and receive exact change,
        output -1.

SAMPLE OUTPUT:

3

OUTPUT DETAILS:

Farmer John pays 75 cents using a 50 cents and a 25 cents coin, and
receives a 5 cents coin in change, for a total of 3 coins used in
the transaction.
