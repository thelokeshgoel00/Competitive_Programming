#include<stdio.h>
int main()
{
    int x1,v1,x2,v2;
    scanf("%d%d%d%d",&x1,&v1,&x2,&v2);
    if(x1>x2&&v1>v2)
    {
        printf("NO");
        return 0;
    }
    else if(x1<x2&&v1<v2)
    {
        printf("NO");
        return 0;
    }
    else if(x1!=x2&&v1==v2)
    {
        printf("NO");
        return 0;
    }
    else if((x1-x2)%(v2-v1)==0)
    {
        printf("YES");
    }
    else printf("NO");
    return 0;
}
