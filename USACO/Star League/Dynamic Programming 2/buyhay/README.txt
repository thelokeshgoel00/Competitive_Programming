Buying Hay
==========

Farmer John is running out of supplies and needs to purchase H (1
<= H <= 50,000) pounds of hay for his cows.

He knows N (1 <= N <= 100) hay suppliers conveniently numbered 1..N.
Supplier i sells packages that contain P_i (1 <= P_i <= 5,000)
pounds of hay at a cost of C_i (1 <= C_i <= 5,000) dollars. Each
supplier has an unlimited number of packages available, and the
packages must be bought whole.

Help FJ by finding the minimum cost necessary to purchase at least
H pounds of hay.

PROBLEM NAME: buyhay

INPUT FORMAT:

* Line 1: Two space-separated integers: N and H

* Lines 2..N+1: Line i+1 contains two space-separated integers: P_i
        and C_i

SAMPLE INPUT:

2 15
3 2
5 3

OUTPUT FORMAT:

* Line 1: A single integer representing the minimum cost FJ needs to
        pay to obtain at least H pounds of hay.

SAMPLE OUTPUT:

9

OUTPUT DETAILS:

FJ can buy three packages from the second supplier for a total cost of 9.
