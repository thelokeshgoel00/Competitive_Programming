#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define PB push_back
#define F first
#define S second
 
 
 
 
int solve(){
    
     ll x,y;
        cin>>x>>y;
     ll mx =max(x,y);
     ll mn = min(x,y);
 
     ll corner = mx*mx - (mx-1);
 
     if(mx%2){
        if(mx==x){
            cout<<corner - mx + y<<endl;
        }else{
            cout<<corner + mx -x<<endl;
        }
     }else{
        if(mx == x){
            cout<<corner + mx - y<<endl;
        }else{
            cout<<corner - mx + x<< endl;
        }
     }
 
    return 0;
}
 
int main(){
    
    ll t=1;
    cin>>t;
 
    while(t--)
        solve();
 
 
    return 0;
}