//I've been expecting you <3
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
int main(){
    int amount,n;
    cin>>amount>>n;
    int memo[amount+1];
    vector<int> coins(n);
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    memo[0]=0;
    for(int i=1; i<=amount; i++){
        memo[i]=0;
        for(int j=0; j<coins.size(); j++){
            if(coins[j]<=i){
                memo[i]=max(memo[i],1+ memo[i-coins[j]]);
            }
            cout<<memo[i]<<" ";
        }
        cout<<endl;
    }
}