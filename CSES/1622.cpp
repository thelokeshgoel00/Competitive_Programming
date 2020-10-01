#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define PB push_back
#define F first
#define S second
 
 
void permutation(string st,set< string > &s,ll index,ll n){
    
    s.insert(st);
    if(index==n) return;
    
    for(int i=index;i<n;i++){
        string temp = st;
 
        swap(temp[i],temp[index]);
        permutation(temp,s,index+1,n);
    }
    return;
 
}
 
int solve(){
    
    string st;
    cin>>st;
    ll n = st.length();
    set< string > s;
    permutation(st,s,0,n);
 
    ll k = s.size();
    cout<<k<<endl;
    for(auto i:s){
        cout<<i<<endl;
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