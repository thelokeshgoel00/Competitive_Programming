#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define PB push_back
#define F first
#define S second
 
 
 
 
int solve(){
    
     ll n,m,k; cin>>n>>m>>k;
 
     multiset< ll > buy,flats;
 
     ll val; 
 
     for(int i=0;i<n;i++) {
        cin>>val;
        buy.insert(val);
     }
 
     for(int i=0;i<m;i++){
        cin>>val;
        flats.insert(val);
     }
     
     ll cnt=0;
     for(auto i:buy){
        
        ll a = i;
 
        auto  j = flats.lower_bound(a-k);
        if(j==flats.end()) break;
 
        ll b = (*j);
        if(b>=a-k && b<=a+k){
            cnt++;
            flats.erase(j);
        }
 
     }
 
     cout<<cnt<<endl;
 
 
    return 0;
}
 
int main(){
    
    ll t=1;
    //    cin>>t;
 
    while(t--)
        solve();
 
 
    return 0;
}