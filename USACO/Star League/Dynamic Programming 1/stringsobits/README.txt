Stringsobits
============

Consider an ordered set S of strings of N (1 <= N <= 31) bits. 
Bits, of course, are either 0 or 1.

This set of strings is interesting because it is ordered and 
contains all possible strings of length N that have L (1 <= L <= N) 
or fewer bits that are '1'.

Your task is to read a number I (1 <= I <= sizeof(S)) from the 
input and print the Ith element of the ordered set for N bits with 
no more than L bits that are '1'.

PROGRAM NAME: kimbits

INPUT FORMAT:

* Line 1: A single line with three space separated integers: 
N, L, and I.

SAMPLE INPUT:

5 3 19

OUTPUT FORMAT:

* Line 1: A single line containing the integer that represents 
the Ith element from the order set, as described.

SAMPLE OUTPUT:

10011
