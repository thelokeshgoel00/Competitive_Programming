Hotel
=====

The cows are journeying north to Thunder Bay in Canada to gain
cultural enrichment and enjoy a vacation on the sunny shores of
Lake Superior. Bessie, ever the competent travel agent, has named
the Bullmoose Hotel on famed Cumberland Street as their vacation
residence. This immense hotel has N (1 <= N <= 50,000) rooms all
located on the same side of an extremely long hallway (all the
better to see the lake, of course).

The cows and other visitors arrive in groups of size D_i (1 <= D_i
<= N) and approach the front desk to check in. Each group i requests
a set of D_i contiguous rooms from Canmuu, the moose staffing the
counter.  He assigns them some set of consecutive room numbers
r..r+D_i-1 if they are available or, if no contiguous set of rooms
is available, politely suggests alternate lodging. Canmuu always
chooses the value of r to be the smallest possible.

Visitors also depart the hotel from groups of contiguous rooms.
Checkout i has the parameters X_i and D_i which specify the vacating
of rooms X_i..X_i+D_i-1 (1 <= X_i <= N-D_i+1). Some (or all) of
those rooms might be empty before the checkout.

Your job is to assist Canmuu by processing M (1 <= M < 50,000)
checkin/checkout requests. The hotel is initially unoccupied.

PROBLEM NAME: hotel

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M

* Lines 2..M+1: Line i+1 contains request expressed as one of two
        possible formats: (a) Two space separated integers
        representing a check-in request: 1 and D_i (b) Three
        space-separated integers representing a check-out: 2, X_i, and
        D_i

SAMPLE INPUT:

10 6
1 3
1 3
1 3
1 3
2 5 5
1 6

OUTPUT FORMAT:

* Lines 1.....: For each check-in request, output a single line with a
        single integer r, the first room in the contiguous sequence of
        rooms to be occupied. If the request cannot be satisfied,
        output 0.

SAMPLE OUTPUT:

1
4
7
0
5

Note: An almost-identical version of this problem appeared in USACO's 2013
Gold January Contest as "Seating". The tenfold increase in bounds did not
break my segment tree solution. :)
