//I've been expecting you <3
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            int k;
            cin>>k;
            v[i].pb(k);
        }
    }
    
}