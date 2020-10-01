#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char str[82];
    gets(str);
    char str2[82];
    int i=0,j=0;
    while(str[i]!='\0')
    {
        if(str[i]!=" ")
        {
            str2[j]=str[i];
            j++;
        }
        i++;
    }
    str2[j]='\0';
    int len=j;
    int a=sqrt(len),b=sqrt(len);
    if(a*b<len)
    {
        b=b+1;
    }
    if(a*b<len)
    {
        a=a+1;
    }
    for(i=0;i<b;i++)
    {
        int k=i;
        j=0;
        for(j=0;j<a;j++)
        {
            if(k<strlen(str2))
            {
                printf("%c",str2[k]);
            }
            k=k+b;
        }
        printf(" ");
    }
    return 0;
}
