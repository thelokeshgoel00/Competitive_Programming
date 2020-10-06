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
     while(n!=1){
        cout<<n<<" ";
        if(n%2) n= n*3+1;
        else n/=2;
 
     }
     cout<<1<<endl;
 
    return 0;
}