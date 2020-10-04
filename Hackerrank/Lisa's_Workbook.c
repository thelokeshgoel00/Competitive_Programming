#include<stdio.h>
#include<string.h>
int workbook(int n,int m,int *a)
{
    int count=0,count1=0,i,j;
for(i=0;i<n;i++)
{
    int temp1=count;
       count+=a[i]/m;
       if((a[i]%m)>0)
       count++;
      temp1++;
     for(j=1;j<=a[i];j++)
     {
         if(j==temp1)
         count1++;
          if(j%m==0)
         temp1++;
     }
}
return count1;
}
main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n],i;
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    int result=workbook(n,m,a);
    printf("%d",result);
}
