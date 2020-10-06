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
/*The Utopian Tree goes through 2 cycles of growth every year. Each spring, it doubles in height. Each summer, its height increases by 1 meter.

A Utopian Tree sapling with a height of 1 meter is planted at the onset of spring. How tall will the tree be after  growth cycles?*/
