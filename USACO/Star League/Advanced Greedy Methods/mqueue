The Milk Queue
==============

Every morning, Farmer John's N (1 <= N <= 25,000) cows all line up
for milking. In an effort to streamline the milking process, FJ has
designed a two-stage milking process where the line of cows progresses
through two barns in sequence, with milking taking part sequentially
in both barns. Farmer John milks cows one by one as they go through
the first barn, and his trusty sidekick Farmer Rob milks the cows
(in the same order) as they are released from the first barn and
enter the second barn.

Unfortunately, Farmer John's insistence that the cows walk through
both barns according to a single ordering leads to some inefficiencies.
For example, if Farmer John takes too long to milk a particular
cow, Farmer Rob might end up sitting idle with nothing to do for
some time. On the other hand, if Farmer John works too fast then
we might end up with a long queue of cows waiting to enter the
second barn.

Please help Farmer John decide on the best possible ordering of
cows to use for the milking, so that the last cow finishes milking
as early as possible. For each cow i we know the time A(i) required
for milking in the first barn and the time B(i) required for milking
in the second barn.  Both A(i) and B(i) are in the range 1...20,000.

PROBLEM NAME: mqueue

INPUT FORMAT:

* Line 1: A single integer, N.

* Lines 2..1+N: Line i+1 contains two space-separated integers A(i)
        and B(i) for cow i.

SAMPLE INPUT:

3
2 2
7 4
3 5

INPUT DETAILS:

There are three cows.  Cow #1 takes 2 units of time in both barns,
cow #2 takes 7 units of time in the first barn and 4 in the second,
and cow #3 takes 3 units of time in the first barn and 5 in the
second.

OUTPUT FORMAT:

* Line 1: The minimum possible time it takes to milk all the cows, if
        we order them optimally.

SAMPLE OUTPUT:

16

OUTPUT DETAILS:

Ordering the cows in the order 3, 1, 2, will allow for milking to complete
within only 16 units of time.
