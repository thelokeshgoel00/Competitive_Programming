//I've been expecting you <3
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,max_so_far=0,max_ending_here=0;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
            max_so_far+=a[i];
            if(max_so_far<0){
                max_so_far=0;
            }
            max_ending_here=max(max_ending_here,max_so_far);
        }
        cout<<max_so_far<<endl;
    }
    
}