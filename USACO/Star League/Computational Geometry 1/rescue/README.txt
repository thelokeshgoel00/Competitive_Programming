Cow Rescue
==========

Bessie is trapped in a triangular maze with N rows (1 <= N <=
1,000,000). A three row maze is shown below:

(First Picture)
(https://docs.google.com/document/d/1Xes_6gYyQtFtcNqq3g-A4glPP_RrfdPqloiqV-XDZOg/edit?usp=sharing)

The i'th row of the maze contains 2*i-1 triangles. Numbering from
the left, the triangles are named (i,1), (i,2), and so on.

Bessie can travel to the (often three) triangles which share an
edge with her current triangle. For example, if she is at (3, 3),
she can travel to (3, 2), (3, 4) and (4, 4). Bessie takes one minute
to travel from one triangle to the next.

(Second Picture)
(https://docs.google.com/document/d/1Xes_6gYyQtFtcNqq3g-A4glPP_RrfdPqloiqV-XDZOg/edit?usp=sharing)

FJ has learned the Bessie is trapped and knows by tracking her
iPhone that she starts her exit trek at triangle (Si,Sj). FJ's love
for Bessie knows no bounds so he wants her back in the minimum
possible time.

The maze has M (1 <= M <= 10,000) exits found in locations throughout
the set of triangles. Any one of these will enable Bessie to escape.
Once she enters an exit triangle, she leaves the maze in just one
more minute.

Find the minimum time in minutes, T, required for Bessie to exit
the maze and report the optimal exit location she uses, (OUTi,
OUTj). If more than one location requires only T minutes, output
the location with the smallest row. If two optimal rows are the
same, output the one with smaller column.

PROBLEM NAME: rescue

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M

* Line 2: Two space-separated integers: Si and Sj

* Lines 3..M+2: Line i+2 contains two space-separated integers that
        are the triangle location of exit i: Ei and Ej

SAMPLE INPUT:

4 2
2 1
3 5
4 4

OUTPUT FORMAT:

* Line 1: Two space-separated integers: OUTi and OUTj

* Line 2: A single integer: T

SAMPLE OUTPUT:

4 4
4
