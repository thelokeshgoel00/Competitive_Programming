#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define PB push_back
#define F first
#define S second
 
 
 
 
int solve(){
    
    string st; cin>>st;
    vector< ll > v(26,0);
    for(auto i:st){
        v[i-'A']++;
    }
 
    ll oddcnt=0;
    char ch = '0';
    for(auto i:v) 
        {    
            if(i%2) oddcnt++;}
     
 
    if(oddcnt>1) return cout<<"NO SOLUTION"<<endl,0;
    else{
        for(int i=0;i<26;i++){
        if(v[i]%2) ch = 'A'+i;
     }
        if(oddcnt>0) v[ch-'A']--;
        st="";
        for(int i=0;i<26;i++){
          for(int j=0;j<(v[i]+1)/2;j++){
            st+=('A'+i);
          }
        }
        if(oddcnt>0) st+=ch;
        for(int i=25;i>=0;i--){
          for(int j=0;j<(v[i]+1)/2;j++){
            st+=('A'+i);
          }
        }
 
    }
    cout<<st<<endl;
    return 0;
}
 
int main(){
    
    ll t=1;
    //    cin>>t;
 
    while(t--)
        solve();
 
 
    return 0;
}