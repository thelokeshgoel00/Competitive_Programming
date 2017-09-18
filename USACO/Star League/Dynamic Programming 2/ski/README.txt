Ski Lessons
===========

Farmer John wants to take Bessie skiing in Colorado. Sadly, Bessie
is not really a very good skier.

Bessie has learned that the ski resort is offering S (0 <= S <=
100) ski classes throughout the day. Lesson i starts at time M_i
(1 <= M_i <= 10,000) and lasts for time L_i (1 <= L_i <= 10,000).
After lesson i, Bessie's ski ability becomes A_i (1 <= A_i <= 100).
Note: this ability is an absolute, not an incremental change.

Bessie has purchased a map which shows all N (1 <= N <= 10,000) ski
slopes along with the time D_i (1 <= D_i <= 10,000) required to ski
down slope i and the skill level C_i (1 <= C_i <= 100) required to
get down the slope safely. Bessie's skill level must be greater
than or equal to the skill level of the slope in order for her to
ski down it.

Bessie can devote her time to skiing, taking lessons, or sipping
hot cocoa but must leave the ski resort by time T (1 <= T <= 10,000),
and that means she must complete the descent of her last slope
without exceeding that time limit.

Find the maximum number of runs Bessie can complete within the time
limit. She starts the day at skill level 1.

Extra feedback will be provided on the first 50 submissions.

PROBLEM NAME: ski

INPUT FORMAT:

* Line 1: Three space-separated integers: T, S, and N

* Lines 2..S+1: Line i+1 describes ski lesson i with three
        space-separated integers: M_i, L_i, and A_i

* Lines S+2..S+N+1: Line S+i+1 describes ski slope i with two
        space-separated integers: C_i and D_i.

SAMPLE INPUT:

10 1 2
3 2 5
4 1
1 3

OUTPUT FORMAT:

A single integer on a line by itself, the maximum number of runs that
Bessie may ski within the time limit.

SAMPLE OUTPUT:

6

OUTPUT DETAILS:

Ski the second slope once, take the lesson, and ski the first slope 5 times
before time is up: a total of 6 slopes.
