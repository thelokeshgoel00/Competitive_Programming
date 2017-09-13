Light Switching
===============

Farmer John tries to keep the cows sharp by letting them play with
intellectual toys. One of the larger toys is the lights in the barn.
Each of the N (2 <= N <= 100,000) cow stalls conveniently numbered
1..N has a colorful light above it.

At the beginning of the evening, all the lights are off. The cows
control the lights with a set of N pushbutton switches that toggle
the lights; pushing switch i changes the state of light i from off
to on or from on to off.
The cows read and execute a list of M (1 <= M <= 100,000) operations
expressed as one of two integers (0 <= operation <= 1).

The first kind of operation (denoted by a 0 command) includes two
subsequent integers S_i and E_i (1 <= S_i <= E_i <= N) that indicate
a starting switch and ending switch. They execute the operation by
pushing each pushbutton from S_i through E_i inclusive exactly once.

The second kind of operation (denoted by a 1 command) asks the cows
to count how many lights are on in the range given by two integers
S_i and E_i (1 <= S_i <= E_i <= N) which specify the inclusive range
in which the cows should count the number of lights that are on.

Help FJ ensure the cows are getting the correct answer by processing
the list and producing the proper counts.

PROBLEM NAME: lites

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M

* Lines 2..M+1: Each line represents an operation with three
        space-separated integers: operation, S_i, and E_i

SAMPLE INPUT:

4 5
0 1 2
0 2 4
1 2 3
0 2 4
1 1 4

INPUT DETAILS:

Four lights; five commands. Here is the sequence that should
be processed:

	    Lights
            1 2 3 4
  Init:     O O O O   O = off  * = on
  0 1 2 ->  * * O O  toggle lights 1 and 2
  0 2 4 ->  * O * *
  1 2 3 ->  1        count the number of lit lights in range 2..3
  0 2 4 ->  * * O O  toggle lights 2, 3, and 4
  1 1 4 ->  2        count the number of lit lights in the range 1..4

OUTPUT FORMAT:

* Lines 1..number of queries: For each output query, print the count
        as an integer by itself on a single line.

SAMPLE OUTPUT:

1
2
