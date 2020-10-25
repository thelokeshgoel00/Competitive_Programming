//I've been expecting you <3
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ar[n];
        for(int i=0; i<n; i++){
            cin>>ar[i];
        }
        ll cnt=n,len=1;
        for(int i=0; i<n-1; i++){
            if(ar[i+1]>=ar[i]){
                len++;
            }
            else{
                cnt+=(((len-1)*len)/2);
                len=1;
            }
        }
        if(len>1){
            cnt+=(((len-1)*len)/2);
        }
        cout<<cnt<<endl;
    }
}