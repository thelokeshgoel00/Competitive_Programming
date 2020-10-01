#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define PB push_back
#define F first
#define S second
 
 
 
 
int solve(){
    
 
    ll n,k; cin>>n>>k;
 
    vector< ll > v(n);
    for(auto &i:v) cin>>i;
 
    ll cnt=0;
    sort(all(v));
 
    ll i=0,j=n-1;
    while(i<=j){
        if(v[i]+v[j]<=k){
            i++;
        }
        cnt++; j--;
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