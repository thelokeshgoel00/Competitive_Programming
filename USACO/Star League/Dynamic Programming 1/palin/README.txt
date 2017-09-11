Palindrome
==========

A palindrome is a symmetrical string, that is, a string read 
identically from left to right as well as from right to left. 
You are to write a program which, given a string, determines 
the minimal number of characters to be inserted into the string 
in order to obtain a palindrome.

As an example, by inserting 2 characters, the string "Ab3bd" can 
be transformed into a palindrome ("dAb3bAd" or "Adb3bdA"). 
However, inserting fewer than 2 characters does not produce a 
palindrome.

PROBLEM NAME: palin

INPUT FORMAT:

* Line 1: A single integer: the length of the input string N, 
       3 <= N <= 5000

* Line 2: one string with length N. The string is formed from 
       uppercase letters from 'A' to 'Z', lowercase letters from 
       'a' to 'z' and digits from '0' to '9'. Uppercase and 
       lowercase letters are to be considered distinct.

SAMPLE INPUT:

5
Ab3bd

OUTPUT FORMAT:

* Line 1: A single integer, which is the desired minimal number.

SAMPLE OUTPUT:

2
