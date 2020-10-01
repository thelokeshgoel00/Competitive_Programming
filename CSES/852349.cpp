#include<bits/stdc++.h>
using namespace std;
 
 
#define ll long long int 
#define all(v) v.begin(),v.end()
#define MOD 1000000007
#define PB push_back
#define F first
#define S second
 
ll pwr(ll a,ll n){
 
    if(n==0) return 1;
 
    if(n==1) return a;
 
    ll ans = pwr(a,n/2);
    ans = ans%MOD;
 
    if(n%2) {
        return (ans*ans*a)%MOD;
    }else{
     return (ans*ans)%MOD;
    }
 
}
 
 
int main(){
     
     ll n; cin>>n;
 
     ll ans = pwr(2,n);
     cout<<ans<<endl;
 
    return 0;
}
