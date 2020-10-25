#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define PB push_back
#define F first
#define S second
 
 
bool comp(pair< ll , ll > &a, pair< ll , ll > &b){
    return a.S<b.S;
}
 
int solve(){
    
     ll n; cin>>n;
     vector< pair< ll , ll >  >v(n);
     for(ll i=0;i<n;i++){
        cin>>v[i].F>>v[i].S;
     } 
 
     sort(all(v),comp);
     ll endt = 0;
     ll cnt=0;
     for(auto i:v){
      if(i.F>=endt){
        cnt++;
        endt = i.S;
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