#include<stdio.h> 
int main()
{
    int q,i,x,y,z;
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(abs(x-z)>abs(y-z))
        {
            printf("Cat B\n");
        }
        else if(abs(x-z)<abs(y-z))
        {
            printf("Cat A\n");
        }
        else 
        {
            printf("Mouse C\n");
        }
    }
    return 0;
}
