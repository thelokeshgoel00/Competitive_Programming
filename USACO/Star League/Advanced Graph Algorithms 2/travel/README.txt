Safe Travel
===========

Gremlins have infested the farm. These nasty, ugly fairy-like
creatures thwart the cows as each one walks from the barn (conveniently
located at pasture_1) to the other fields, with cow_i traveling to
from pasture_1 to pasture_i. Each gremlin is personalized and knows
the quickest path that cow_i normally takes to pasture_i. Gremlin_i
waits for cow_i in the middle of the final cowpath of the quickest
route to pasture_i, hoping to harass cow_i.

Each of the cows, of course, wishes not to be harassed and thus
chooses an at least slightly  different route from pasture_1 (the
barn) to pasture_i.

Compute the best time to traverse each of these new not-quite-quickest
routes that enable each cow_i that avoid gremlin_i who is located
on the final cowpath of the quickest route from pasture_1 to
pasture_i.

As usual, the M (2 <= M <= 200,000) cowpaths conveniently numbered
1..M are bidirectional and enable travel to all N (3 <= N <= 100,000)
pastures conveniently numbered 1..N. Cowpath i connects pastures
a_i (1 <= a_i <= N) and b_i (1 <= b_i <= N) and requires t_i (1 <=
t_i <= 1,000) time to traverse. No two cowpaths connect the same
two pastures (a_i != b_i). Best of all, the shortest path regularly
taken by cow_i from pasture_1 to pasture_i is unique in all the
test data supplied to your program.

By way of example, consider these pastures, cowpaths, and [times]:

      1--[2]--2-------+
      |       |       |
     [2]     [1]     [3]
      |       |       |
      +-------3--[4]--4

   TRAVEL     BEST ROUTE   BEST TIME   LAST PATH
p_1 to p_2       1->2          2         1->2
p_1 to p_3       1->3          2         1->3
p_1 to p_4      1->2->4        5         2->4

When gremlins are present:

   TRAVEL     BEST ROUTE   BEST TIME    AVOID
p_1 to p_2     1->3->2         3         1->2
p_1 to p_3     1->2->3         3         1->3
p_1 to p_4     1->3->4         6         2->4

For 20% of the test data, N <= 200.

For 50% of the test data, N <= 3000.

PROBLEM NAME: travel

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M

* Lines 2..M+1: Three space-separated integers: a_i, b_i, and t_i


SAMPLE INPUT:

4 5
1 2 2
1 3 2
3 4 4
3 2 1
2 4 3

INPUT DETAILS:

As in the text example.

OUTPUT FORMAT:

* Lines 1..N-1: Line i contains the smallest time required to travel
        from pasture_1 to pasture_i+1 while avoiding the final cowpath
        of the shortest path from pasture_1 to pasture_i+1. If no such
        path exists from pasture_1 to pasture_i+1, output -1 alone on
        the line.

SAMPLE OUTPUT:

3
3
6

OUTPUT DETAILS:

As in the text example.
