//I've been expecting you <3
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
#define lb lower_bound
#define fr(i,n) for(int i=0; i<n; i++)
int main(){
    int n,k,p;
    cin>>n>>k>>p;
    vector<int> vo(n),vd(n);
    fr(i,n){
        cin>>vo[i];
        vd[i]=vo[i];
    }
    sort(vd.begin(),vd.end(), greater<int>());
    map<int, int> m;
    m[vd[0]]=vd[0]+k;
    for(int i=1;i<n;i++){
        if(vd[i-1]-vd[i]<=k){
            m[vd[i]]=m[vd[i-1]];
        }
        else m[vd[i]]=vd[i]+k;
    }
    fr(i,p){
        int a,b;
        cin>>a>>b;
        // auto it1=lb(vd.begin(),vd.end(),vo[a-1]);
        // auto it2=lb(vd.begin(),vd.end(),vo[b-1]);
        if(m[vo[--a]]==m[vo[--b]]){
            cout<<"Yes";
        }
        else cout<<"No";
        cout<<endl;
    }
}