//I've been expecting you <3
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
int main(){
    int n,amt;
    cin>>n>>amt;
    int ar[n];
    for(int i=0; i<n; i++){
        cin>>ar[i];
    }
    int memo[amt+1];
    memo[0]=0;
    for(int i=1; i<=amt; i++){
        memo[i]=amt+1;
        for(int j=0; j<n;j++){
            if(ar[j]<=i){
                memo[i]=min(memo[i],1+memo[i-ar[j]]);
            }
            else{
                continue;
            }
        }
    }
    if(memo[amt]==amt+1){
        cout<<-1;
    }
    else{
        cout<<memo[amt];
    }
}