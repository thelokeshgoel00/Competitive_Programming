#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int freq[5]={0,0,0,0,0};
    for(i=0;i<n;i++)
    {
        freq[arr[i]-1]++;
    }
    int index=0;
    for(i=1;i<5;i++)
    {
        if(freq[i]>freq[index])
        {
            index=i;
        }
    }
    printf("%d",index+1);
    return 0;
}
