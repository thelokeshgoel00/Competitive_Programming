#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define PB push_back
#define F first
#define S second
 
 
 
 
int solve(){
    
     ll x,n;
     cin>>x>>n;
 
     multiset< ll > dist;
     set < ll > pos;
 
     dist.insert(x);
     pos.insert(0);
     pos.insert(x);
 
     ll val;
     while(n--){
        cin>>val;
        pos.insert(val);
        
        auto valpos = pos.find(val);
        valpos++;
        ll uval = (*valpos);
        valpos--;
        valpos--;
        ll lval = (*valpos);
 
        ll d = uval - lval;
        auto add = dist.find(d);
        dist.erase(add);
 
 
        dist.insert(uval - val);
        dist.insert(val-lval);
 
        cout<<(*dist.rbegin())<<" ";
 
     }
     cout<<endl;
 
 
 
    return 0;
}
 
int main(){
    
    ll t=1;
    // cin>>t;
 
    while(t--)
        solve();
 
 
    return 0;
}