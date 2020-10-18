#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lli t,n,x,p;cin>>t;
    lli sum;
    while(t--)
    {   
        sum = 0;
        cin>>n;
        cin>>p;
        n--;
        while(n--){
            cin>>x;
            sum+=abs(x-p)-1;
            p=x;
        }
        cout<<sum<<"\n";
    }
    return 0;
}