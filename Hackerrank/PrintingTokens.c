
/* https://www.hackerrank.com/challenges/printing-tokens-/problem */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    char *s;
    char *temp;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    int l = strlen(s);
    //Write your logic to print the tokens of the sentence here.
    for (int i = 0; i < l; i++)
    {
        if (s[i] == ' ')
        {
            printf("\n");
        }
        else
        {
            printf("%c", s[i]);
        }
    }

    return 0;
}
