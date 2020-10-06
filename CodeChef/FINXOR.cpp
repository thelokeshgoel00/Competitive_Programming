#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long long int t,c=1048576,n,in,sum,i,ans,temp,diff,fact,diff2;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<'1'<<" "<<c<<"\n";
        fflush(stdout);
        cin>>in;
        sum=in-c*n;
        //cout<<"sum="<<sum;
        i=0;
        if (sum%2==0)
            ans=0;
        else
            ans=1;
        for (i=19;i>0;i--)
        {
            cout<<'1'<<" "<<pow(2,i)<<"\n";
            fflush(stdout);
            cin>>in;
            if (in==sum)
            {
                temp=n/2;
                if (temp%2!=0)
                    ans+=pow(2,i);
            }
            else if (in>sum)
            {
                diff=in-sum;
                fact=diff/pow(2,i);
                diff2=(n-fact)/2;
                if (diff2%2!=0)
                    ans+=pow(2,i);
            }
            else
            {
                diff=sum-in;
                fact=diff/pow(2,i);
                temp=fact;
                diff2=(n-fact)/2;
                if ((diff2+temp)%2!=0)
                    ans+=pow(2,i);
            }
        }
        cout<<'2'<<" "<<ans<<"\n";
        fflush(stdout);
        cin>>in;
        if (in==1)
            continue;
        else
            return -1;
    }
    return 0;
}