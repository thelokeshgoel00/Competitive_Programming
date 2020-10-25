#include<stdio.h>
int no_of_dig(long int i)
{
    int dig=0;
    long int m=i;
    while(m!=0)
    {
        m=m/10;
        dig++;
    }
    return dig;
}
int main()
{
    long int a,b;
    scanf("%d%d",&a,&b);
    long int i,j;
    int count=0;
    for(i=a;i<=b;i++)
    {
        long int sq=i*i;
        int dig1=no_of_dig(i);
        long int div=1;
        for(j=0;j<dig1;j++)
        {
            div=div*10;
        }
        long int left=sq/(div);
        long int right=sq%(div);
        if(left+right==i)
        {
            count++;
            printf("%d ",i);
        }
    }
    if(count==0)
    {
        printf("INVALID RANGE\n");
    }
    return 0;
}
