#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() 
{
    int T,j;
    cin>>T;
    for (j=0;j<T;j++)
    {
        long long int n,k;
        cin>>n;
        cin>>k;
        long long int a[n],b[n],i,c,sum=0,mul,sub,max;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(c=0;c<n;c++)
        {
            cin>>b[c];
        }
        max=b[0];
        for(c=0;c<n;c++)
        {
        if(max<b[c])
            max=b[c];   
        }
       for(i=0;i<n;i++)
       {
           if((max+1)>a[i])
           {
           sub=(max+1)-a[i];
           mul=sub*k;
           sum=sum+mul;
           }
       }
        cout<<sum<<endl;
    }
    return 0;
}
