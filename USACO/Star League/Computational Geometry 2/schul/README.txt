Cow School
==========

Bessy is going to school and doing well. She has taken N (1 <= N
<= 5000 -- except one case where 1 <= N <= 50,000) tests and recorded
the scores (T_i points out of P_i points for test i; 0 <= T_i <=
P_i < 40,000; 0 < P_i) as this task's input.

Her teacher will drop the D tests with the lowest percentage (T_i/P_i)
before calculating Bessie's final grade (which is the sum of the
remaining test score points over the sum of the remaining total
test points). Bessy is good at math and quickly realizes that this
does not benefit her as much as it might.

To prove her point, Bessy wants to find all values of D for which
she could have ended up with a higher grade by choosing to drop
different tests than the teacher would have. Help her by finding
and printing all values of D for which this is possible.

Bessy has noted that, amazingly, she has never scored the same
percentage on two different tests.

PROBLEM NAME: schul

INPUT FORMAT:

* Line 1: A single integer, N

* Lines 2..N+1: Line i+1 contains two space-separated integers: T_i
        and P_i

SAMPLE INPUT:

5
1 2
5 9
3 8
4 10
1 3


INPUT DETAILS:

Bessy has taken 5 tests so far and has scores of 1/2, 5/9, 3/8, 4/10, and 1/3.

OUTPUT FORMAT:

* Line 1: A single integer K (0 <= K <= N) that is the number of
        values of D for which Bessy could have ended up with a higher
        grade by dropping a different set of D tests than the teacher.

* Lines 2..K+1: The values of D for which this is true, in ascending
        numerical order.

SAMPLE OUTPUT:

2
1
2

OUTPUT DETAILS:

For D = 1, dropping 1/3 leads to a final grade of 13/29. A higher
final grade of 11/24 can be achieved if Bessy drops 3/8.

For D = 2, dropping 1/3 and 3/8 lead to a final grade of 10/21. A
higher final grade of 7/14 can be achieved if Bessy drops 3/8 and
4/10.
