#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define PB push_back
#define F first
#define S second
 
 
 
 
int solve(){
    
    ll n,m; 
    cin>>n>>m;
    multiset< ll > ms;
 
    ll val; 
    while(n--){
        cin>>val;
        ms.insert(val);
    }
 
    while(m--){
        cin>>val;
 
        ll sz = ms.size();
        if(sz==0) {
            cout<<-1<<endl;
        }else{
            auto j = ms.upper_bound(val);
            if(j==ms.begin()){
                cout<<-1<<endl;
            }else{
                j = --j;
                cout<<(*j)<<endl;
                ms.erase(j);
            }
        }
    }
 
    return 0;
}
 
int main(){
    
    ll t=1;
    //    cin>>t;
 
    while(t--)
        solve();
 
 
    return 0;
}