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
     vector< ll > v;
     
     if(n==4){
        return cout<<2<<" "<<4<<" "<<1<<" "<<3<<endl,0;
     }
 
     for(ll i=1;i<=n;i+=2){
        v.push_back(i);
     }
 
     for(ll i=2;i<=n;i+=2){
        v.push_back(i);
     }
 
     for(int i=1;i<n;i++){
        if(abs(v[i]-v[i-1])==1) return cout<<"NO SOLUTION"<<endl,0;
     }
 
     for(auto i:v) cout<<i<<" ";
 
     cout<<endl;
 
    return 0;
}