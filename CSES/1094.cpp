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
     vector< ll > v(n);
     for(auto &i:v) cin>>i;
 
     ll cnt=0;
 
     for(ll i=1;i<n;i++){
        if(v[i]<v[i-1]){ cnt= (cnt+(v[i-1]-v[i]));
            v[i]=v[i-1];
        }
     }
     cout<<cnt<<endl;
 
    return 0;
}