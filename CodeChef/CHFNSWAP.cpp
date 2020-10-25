#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int t,n,i,j,sum1,sum2,m,diff,a,b,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        m=pow((n*(n+1)*0.5)+0.25,0.5)-0.5;
        sum1=m*(m+1)/2;
        sum2=(n*(n+1)/2) - sum1;
        diff=abs(sum2-sum1);
        i=m;
        while(diff-(m+1)*2>=0)
        {
            diff=diff-(m+1)*2;
            m++;
        }
        if (diff%2==1)
            cout<<"0"<<"\n";
        else
        {
            ans=0;
            while((n-1)*2>=diff)
            {
                a=m+1-diff/2;
                b=n-diff/2;
                if (a>m && b>m)
                {
                    ans+=(m-1)*m*0.5+(n-m-1)*(n-m)*0.5;
                }
                else if (b<=m && a>=1)
                    ans+=b-a+1;
                else if (b>m)
                    ans+=(diff/2);
                else if(a<1)
                    ans+=b;
                diff+=(2*m);
                m--;
            }
                cout<<ans<<"\n";
        }

    }
    return 0;
}
