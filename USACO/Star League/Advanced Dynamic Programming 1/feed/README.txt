Buying Feed
===========

Farmer John needs to travel to town to pick up K (1 <= K <= 10,000)
pounds of feed. Driving a mile with K pounds of feed costs FJ K*K
cents; driving D miles with K pounds of feed in his truck costs FJ
D*K*K cents.

FJ can purchase feed from any of N (1 <= N <= 500) stores (conveniently
numbered 1..N) that sell feed. Each store is located on a segment
of the X axis whose length is E (1 <= E <= 500) miles. Store i is
at location X_i (0 < X_i < E) on the number line and can sell FJ
as much as F_i (1 <= F_i <= 10,000) pounds of feed at a cost of C_i
(1 <= C_i <= 10,000,000) cents per pound. Surprisingly, a given
point on the X axis might have more than one store.

FJ starts driving at location 0 on this number line and can drive
only in the positive direction, ultimately arriving at location E
with at least K pounds of feed. He can stop at any of the feed
stores along the way and buy any amount of feed up to the the store's
limit.

What is the minimum amount FJ must pay to buy and transport the K
pounds of feed? FJ knows he can purchase enough feed.

Consider this example where FJ needs two pounds of feed which he
must purchase from some of the three stores at locations 1, 3, and
4 on a number line whose range is 0..5:

      0   1   2   3   4   5  X
      +---|---+---|---|---+
          1       1   1      Available pounds of feed
          1       2   2      Cents per pound

It is most economical for FJ to buy one pound of feed from both the
second and third stores. He must pay two cents to buy each pound
of feed for a total cost of 4. FJ's driving from location 0 to
location 3 costs nothing, since he is carrying no feed. When FJ
travels from 3 to 4 he moves 1 mile with 1 pound of feed, so he
must pay 1*1*1 = 1 cents.

When FJ travels from 4 to 5 he moves one mile with 2 pounds of feed,
so he must pay 1*2*2 = 4 cents. 
His feed cost is 2 + 2 cents; his travel cost is 1 + 4 cents. The
total cost is 2 + 2 + 1 + 4 = 9 cents.

PROBLEM NAME: feed

INPUT FORMAT:

* Line 1: Three space-separated integers: K, E, and N

* Lines 2..N+1: Line i+1 contains three space-separated integers: X_i,
        F_i, and C_i

SAMPLE INPUT:

2 5 3
3 1 2
4 1 2
1 1 1

OUTPUT FORMAT:

* Line 1: A single integer that is the minimum cost for FJ to buy and
        transport the feed

SAMPLE OUTPUT:

9
