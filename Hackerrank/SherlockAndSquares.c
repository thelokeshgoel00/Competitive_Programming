#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    int i;
    for(i=0;i<t;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int j;
        int count=0;
        j=a;
        while(j<=b)
        {
            float f=sqrt(j);
            int r=sqrt(j);
            if(f-r!=0)
            {
                j++;
            }
            else
            {
                count++;
                j=j+(r*2+1);
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
