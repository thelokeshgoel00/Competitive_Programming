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
 
    ll sum = (n*(n+1))/2;
    if(sum%2) cout<<"NO"<<endl;
    
    else{
        sum = sum/2;
        vector< ll > a,b;
        ll sum1=0;
        for(ll i=n;i>0;i--){
            if(sum1+i<=sum){
                a.push_back(i);
                sum1+=i;
            }else{
                b.push_back(i);
            }
        }
 
        ll sa = a.size();
        ll sb = b.size();
        cout<<"YES"<<endl;
        cout<<sa<<endl;
        for(auto i:a) cout<<i<<" ";
        cout<<endl;
        cout<<sb<<endl;
        for(auto i:b) cout<<i<<" ";
        cout<<endl;
 
    }
 
    return 0;
 
 
 
 
 
    return 0;
}