#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    long long int t,n,i,j,ans,k,trans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        long long int arr[n];
        for(j=0;j<n;j++)
        {
            cin>>k;
            arr[j]=k;
        }
        for (i=1;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>k;
            }
        }
        trans=0;
        for (i=n-1;i>0;i--)
        {
            if (trans==0 && arr[i]!=i+1)
            {
                ans++;
                trans=1;
            }
            if(trans==1 && arr[i]==i+1)
            {
                ans++;
                trans=0;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
