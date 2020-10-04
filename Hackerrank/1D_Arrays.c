
/* https://www.hackerrank.com/challenges/1d-arrays-in-c/problem */
/* */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n, i, sum = 0;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter the elements : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }

    for (i = 0; i < n; i++)
    {
        sum =sum + *(a + i);
    }

    printf("%d\n", sum);
    free(a);
    return 0;
}
