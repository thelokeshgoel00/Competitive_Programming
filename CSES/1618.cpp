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
 
     ll cnt=0;
     ll pwr = 5;
     while(n/pwr){
        cnt += n/pwr;
        pwr*=5;
     }
 
     cout<<cnt<<endl;
 
    return 0;
}