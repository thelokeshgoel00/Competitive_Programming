#include<bits/stdc++.h>
using namespace std;
 
 
#define ll long long int 
#define all(v) v.begin(),v.end()
#define MOD 1000000007
#define PB push_back
#define F first
#define S second
 
 
int main(){
     
     string st;
     cin>>st;
     ll cnt=1;
     ll mx=0;
     for(ll i=1;i<st.length()+1;i++){
        if(st[i]==st[i-1]) cnt++;
        else{
            mx  = max(mx,cnt);
            cnt=1;
        }
     }
     cout<<mx<<endl;
 
    return 0;
}