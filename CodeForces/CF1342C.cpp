#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fin for(int i=0;i<n;i++)
#define ff first
#define ss second
#define vi vector<int>
#define vc vector<char>
#define vii vector<int,int>
#define pb push_back
#define mp make_pair
ll a,b;
ll sx(ll r){
	ll cnt=0;
	for(ll i=0;i<=r;i++){
		if(((i%a)%b)!=((i%b)%a))
			cnt++;
	}
	return cnt;

}
ll counti(ll r){
	ll mul=a*b;
	ll ans1 = (r/mul)*sx(mul-1);
	ll ans2 = sx(r%mul);
	return ans1+ans2; 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ll t;
    cin>>t;
    while(t--){
    	ll q;
    	cin>>a>>b>>q;
    	while(q--){
    		ll l,r;
    		cin>>l>>r;
    		cout<<counti(r)-counti(l-1)<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}