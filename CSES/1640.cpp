#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define PB push_back
#define F first
#define S second
 
 
 
 
int solve(){
    
     ll n,x; cin>>n>>x;
 
     vector< pair< ll , ll > > v(n);
 
     for(ll i=0;i<n;i++){
        cin>>v[i].F;
        v[i].S = i+1;
     }
 
     sort(all(v));
 
     ll i=0,j=n-1;
 
     while(i<j){
        if(v[i].F+v[j].F==x){
            ll a = min(v[i].S,v[j].S);
            ll b = max(v[i].S,v[j].S);
            cout<<a<<" "<<b<<endl;
            return 0;
        }else if(v[i].F+v[j].F>x){
            j--;
        }else{
            i++;
        }
 
     }
 
     cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
 
int main(){
    
    ll t=1;
    //    cin>>t;
 
    while(t--)
        solve();
 
 
    return 0;
}