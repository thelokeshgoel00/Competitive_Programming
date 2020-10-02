#include<stdio.h>
int main()
{
    int n,d;
    scanf("%d%d",&n,&d);
    int arr[n];
    int i,j,k;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int count=0;
    for(i=0;i<n-2;i++)
    {
        int temp1=arr[i];
        for(j=i+1;j<n-1;j++)
        {
            int temp2=arr[j];
            int diff=temp2-temp1;
            if(diff==d)
            {
                k=j+1;
                while(k<n&&(arr[k]-arr[j])<diff)
                {
                    k++;
                }
                if(k<n)
                {
                    if(arr[k]-arr[j]==diff)
                    {
                        if(diff==d)
                        {
                            count++;
                        }
                        break;
                    }
                }
            }
            else if(diff>d)
            {
                break;
            }
        }
    }
    printf("%d",count);
    return 0;
}
