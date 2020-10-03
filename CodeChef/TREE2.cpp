#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int t,i,ans,n,c;
    cin>>t;
    while(t--)
    {
        ans=1;
        cin>>n;
        int arr[n];
        for (i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        if (arr[n-1]==0)
        {
            cout<<"0\n";
            continue;
        }
        i=0;
        while(arr[i]==0)
            i++;
        c=arr[i];
        for (i=i;i<n;i++)
        {
            if(c!=arr[i])
            {
                ans++;
                c=arr[i];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
