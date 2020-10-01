#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define PB push_back
#define F first
#define S second
 
 
 
 
int solve(){
    
     ll n; cin>>n;
 
     multiset < ll > s;
 
     ll val;
     ll cnt=0;
 
     while(n--){
        cin>>val;
 
        auto i = s.upper_bound(val);
        if(i==s.end()){
            s.insert(val);
            cnt++;
        }else{
            s.erase(i);
            s.insert(val);
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