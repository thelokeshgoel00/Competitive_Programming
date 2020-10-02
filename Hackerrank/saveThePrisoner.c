#include<stdio.h>
int main()  
{
    int t;
    scanf("%d",&t);
    int i;
    for(i=0;i<t;i++)
    {
        long int n,c,s;
        scanf("%ld%ld%ld",&n,&c,&s);
        long int seat=s;
        seat=(seat+c-1)%n;
        if(seat==0)
        {
            seat=n;
        }
        printf("%ld\n",seat);
    }
    return 0;
}
