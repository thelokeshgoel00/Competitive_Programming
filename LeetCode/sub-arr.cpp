//I've been expecting you <3
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
#define CMOD 1000000007
int main(){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0; i<n; i++){
        cin>>ar[i];
    }
    long long ans=0;
    for(int i=0;i<pow(2,n);i++){
        long long sum=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                sum+=ar[j];
            }
        }
        if(sum%2!=0){
            ans=((ans%CMOD)+1%CMOD)%CMOD;
        }
    }
    cout<<ans;
}