Addition Chain
==============

An addition chain is a sequence of integers such that the first number is 1,
and every subsequent number is the sum of the previous number and another
number that appears in the list before it. For example, 1 2 3 5 is such a
chain, as 2 is 1+1, 3 is 2+1, and 5 is 2+3. If we were to add another number
to the chain, it had to be one of these: 1+5, 2+5, 3+5 or 5+5. Find the
minimum length chain that ends with a given number.

PROBLEM NAME: chain

INPUT FORMAT:

* Line 1: A single integer: N <= 20,000

SAMPLE INPUT:

5

OUTPUT FORMAT:

* Line 1: The length of shortest addition chain for N

SAMPLE OUTPUT:

4

OUTPUT EXPLANATION:

5 can be reached in 4 steps: 1 2 3 5
