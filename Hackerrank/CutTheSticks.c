#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int i,j;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n-1;i++)
    {
        int minindex=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minindex])
            {
                minindex=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minindex];
        arr[minindex]=temp;
    }
    int m=n;
    i=0;
    while(m>0)
    {
        printf("%d\n",m);
        int cut=arr[i];
        for(j=0;j<n;j++)
        {
            arr[j]=arr[j]-cut;
        }
        while(arr[i]==arr[i+1])
        {
            i++;
            m--;
        }
        i++;
        m--;
    }
    return 0;
}
