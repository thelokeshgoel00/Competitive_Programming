#include<stdio.h>
int main()
{
    int n,r,k;
    scanf("%d%d%d",&n,&r,&k);
    int i;
    int arr[n];
    int search[k];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<k;i++)
    {
        scanf("%d",&search[i]);
        int index=(search[i]-r)%n;
        if(index<0)
        {
            index=index+n;
        }
        printf("%d\n",arr[index]);
    }
    return 0;
}
