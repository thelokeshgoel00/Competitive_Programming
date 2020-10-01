#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define PB push_back
#define F first
#define S second
 
 
 
 
int solve(){
    
     ll n; 
     cin>>n;
     
     vector< pair< pair< ll , ll >, ll> > v(n);
 
     for(ll i=0;i<n;i++){
        cin>>v[i].F.F>>v[i].F.S;
        v[i].S = i;
 
     }
 
    priority_queue< pair< ll , ll > , vector< pair< ll , ll > > , greater < pair< ll , ll > > > pq;
 
    ll enter,leave;
    sort(all(v)); 
    ll mxroom = 1;
    pq.push({0,1});
    vector< ll > ans(n);
   for(auto i:v){
            
        enter = i.F.first;
        leave = i.F.second;
        cin>>enter>>leave;
        pair< ll , ll > a = pq.top();
        if(a.first < enter){
            pq.pop();
            pq.push({leave,a.second});
            ans[i.second]= a.second;
        }else{
            mxroom++;
            ans[i.second]=mxroom;
            pq.push({leave,mxroom});
 
        }
    }
 
    cout<<mxroom<<endl;
    
    return 0;
}
 
int main(){
    
    ll t=1;
  

// input 
// 3
// 5 8
// 2 4
// 3 9
// output 
// 2
 
    while(t--)
        solve();
 
 
    return 0;
}