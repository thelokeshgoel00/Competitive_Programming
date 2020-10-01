#include<bits/stdc++.h>
using namespace std;
 
 
#define ll long long int 
#define all(v) v.begin(),v.end()
#define MOD 1000000007
#define PB push_back
#define F first
#define S second
 
 
int main(){
     
     ll n; cin>>n;
     vector< ll > v(n+1,0);
     ll k = n-1;
     while(k--){
        ll val ; cin>>val;
        v[val]=1;
     }
     for(ll i=1;i<n+1;i++){
        if(v[i]==0) return cout<<i<<" "<<endl,0;
     }
 
    return 0;
}