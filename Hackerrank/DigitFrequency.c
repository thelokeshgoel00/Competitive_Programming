
/* https://www.hackerrank.com/challenges/frequency-of-digits-1/problem */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char *s;
    int cnt = 0;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    int len = strlen(s);

    for (int i = '0'; i <= '9'; i++)
    {
        cnt = 0;
        for (int j = 0; j < len; j++)
        {
            if (s[j] == i)
            {
                cnt++;
            }
        }
        printf("%d ", cnt);
    }

    return 0;
}
