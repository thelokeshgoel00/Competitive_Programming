#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fin for(int i=0;i<n;i++)
#define ff first
#define ss second
#define vi vector<int>
#define vc vector<char>
#define vii vector<int,int>int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ll t;
    ll a[1000005];
    ll ans[100005];
    cin>>t;
    while(t--){
    	ll n,q;
    	cin>>n>>q;
    	fin{
    		cin>>a[i];
    	}

    	// for(int i=0;)
    	while(q--){
    	ll l,r;
    	cin>>l>>r;
    	ll count=0;
    	for(ll i=l;i<=r;i++)
    	{
    		for(ll j=i;j<=r;j++)
    		{
    			if((a[i]^a[j])>=l && (a[i]^a[j])<=r)
    				count++;
    		}
    	}
    	cout<<count<<endl;
    }
}
    return 0;
}