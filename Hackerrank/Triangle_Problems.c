
/* https://www.hackerrank.com/challenges/small-triangles-large-triangles/problem */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
    int a;
    int b;
    int c;
};

typedef struct triangle triangle;

int area(struct triangle tr)
{
    int a = tr.a, b = tr.b, c = tr.c;
    int s = (a + b + c) / 2;
    return (a + b + c) * (a + b - c) * (a - b + c) * (-a + b + c);
}

void sort_by_area(triangle *tr, int n)
{
    /**
	* Sort an array a of the length n
	*/
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (area(tr[i]) > area(tr[j]))
            {
                struct triangle temp = tr[i];
                tr[i] = tr[j];
                tr[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    triangle *tr = malloc(n * sizeof(triangle));
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
    }
    sort_by_area(tr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
    }
    return 0;
}