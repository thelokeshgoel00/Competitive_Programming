/*

https://www.hackerrank.com/challenges/big-sorting/problem


*/


#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    char arr[n][1000001];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%s",arr[i]);
    }
    for(i=0;i<n-1;i++)
    {
        int minindex = i;
        int j;
        for(j=i+1;j<n;j++)
        {
            if(strlen(arr[j])<strlen(arr[minindex]))
            {
                minindex = j;
            }
            else  
            {
                if(strlen(arr[j])==strlen(arr[minindex]))
                {
                    if(strcmp(arr[j],arr[minindex])<0)
                    {
                        minindex = j;
                    }
                }
            }
        }
        char temp[1000001];
        strcpy(temp,arr[minindex]);
        strcpy(arr[minindex],arr[i]);
        strcpy(arr[i],temp);

    }

    for(i=0;i<n;i++)
    {
        printf("%s\n",arr[i]);
    }
    return 0;
}
