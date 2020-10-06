
/* https://www.hackerrank.com/challenges/reverse-array-c */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr,*rev_arr, i,j;
    printf("Enter the number of elements ");
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    rev_arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }

    for(i = num-1,j=0; i>=0&&j<num; i--,j++){
      *(rev_arr+j)=*(arr+i);
    }
    for(int i=0;i<num;i++)
    {
        *(arr+i)=*(rev_arr+i);
        printf("%d ",*(arr+i));
    }
    return 0;
}


/*
int main()
{
    int num, *arr, i, temp;
    scanf("%d", &num);
    arr = (int *)malloc(num * sizeof(int));
    for (i = 0; i < num; i++)
    {
        scanf("%d", arr + i);
    }

    /* Write the logic to reverse the array. */
    for (int m = 0, n = num - 1; m < n; m++, n--)
    {
        temp = arr[m];
        arr[m] = arr[n];
        arr[n] = temp;
    }

    for (i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
