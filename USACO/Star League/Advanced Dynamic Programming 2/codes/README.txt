Hidden Codes
============

A set of code words (1 <= N <= 100) and a text (1 <= length of the 
text <= 1,000,000) are given. Each code word has maximum length of 100.
The text is supposed to contain a message made up of the code words 
embedded in the text in a peculiar (and possibly ambiguous) way.

The code words and the text are sequences made up of the upper
and lower case letters of the English alphabet only. Case-sensitivity
is assumed. The length of a code word is defined in the usual way:
For example, the code word ALL has length 3.

The letters of a code word do not have to occur consecutively in the 
given text. For example, the code word ALL will always occur in the 
text within a subsequence in the form of AuLvL where u and v denote
arbitrary (possibly empty) sequences of letters. We say that AuLvL
is a covering sequence for ALL. In general, a covering sequence for
a code word is defined as a subsequence of the text such that the first
letter and the last letter of the subsequence are the same as those of
the code word and it is possible to obtain the code word by deleting
some (possibly none) of the letters of the subsequence. It should be
noted that a code word may occur within one or more covering sequences
or may not occur in the text at all, and that a covering sequence may be
a covering sequence for more than one code word.

A covering sequence is identified by its start position (position of its
first letter) and its end position (position of its last letter) in the
text. (The first letter of the text is at position 1.) We say that two
covering sequences, say c_1 and c_2, do not overlap if the start position
of c_1 is greater than (>) the end position of c_2 or vice versa. 
Otherwise we say that the two covering sequences overlap.

To extract the message hidden in the text you undertake the task of
forming a solution. A solution is a set of items, each consisting of
a code word and a covering sequence for this code word, so that the
following conditions are all satisfied:

a) the covering sequences do not overlap with each other;
b) a covering sequence does not exceed 1000 in length;
c) the sum of the lengths of the code words is maximal. (Each item 
   contributes the length of the code word it contains to the sum.)
     
We say that a covering sequence c for a code word w is right-minimal 
if no proper prefix of c (a proper prefix of c is an initial subsequence
of c that is not equal to c) is a covering sequence for w. For example,
for the code word ALL, AAALAL is a right-minimal covering sequence
whereas AAALALAL is also a covering sequence, but not right-minimal.

It is guaranteed that in the given text:
- for each position in the text the number of right-minimal covering 
  sequences containing that position does not exceed 2500
- the number of right-minimal covering sequences does not exceed 10,000

PROBLEM NAME: codes

INPUT FORMAT:

* Line 1: Single integer N

* Line 2..N+1: each line contains one code word.

* Line N+2: the text

SAMPLE INPUT:

4
RuN
RaBbit
HoBbit
StoP
StXRuYNvRuHoaBbvizXztNwRRuuNNP

OUTPUT FORMAT:

* Line 1: A single integer, the maximal sum described above.

SAMPLE OUTPUT:

12

OUTPUT DETAILS:

The hidden message that could be extracted from the solution 
is "RuN RaBbit RuN". Hence the maximal sum is 12 as follows:

code word  position in text
---------  ----------------
Run        (4,7)
Rabbit     (9,21)
Run        (24 28)

Remark: An alternative solution would yield "RuN HoBbit RuN"
