#include<stdio.h>
int main()
{
    int k;
    scanf("%d",&k);
    int i,j;
    int cycles[k];
    for(i=0;i<k;i++)
    {
        scanf("%d",&cycles[i]);
    }
    for(i=0;i<k;i++)
    {
        int Height=1;
        for(j=1;j<=cycles[i];j++)
        {
            if(j%2!=0)
            {
                Height=Height*2;
            }
            else  
            {
                Height++;
            }
        }
        printf("%d\n",Height);
    }
    return 0;
}
