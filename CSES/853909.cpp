#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define PB push_back
#define F first
#define S second
 
ll diff = INT_MAX;
ll Sum = 0;
 
void mindif(vector< ll > &v,ll index, ll n, ll sum){
 
    if(index == n){
        diff = min(diff,abs((Sum-sum)-sum));
        return;
    }
    mindif(v,index+1,n,sum+v[index]);
    mindif(v,index+1,n,sum);
    return;
}
 
int solve(){
    
    ll n ; cin>>n;
 
    vector< ll > v(n);
    for(auto &i:v) cin>>i;
    
    ll sum =0;
    for(auto i:v) Sum+=i;
    mindif(v,0,n,sum);
    
    cout<<diff<<endl;
 
    return 0;
}
 
int main(){
    
    ll t=1;
    //    cin>>t;
 
    while(t--)
        solve();
 
 
    return 0;
}