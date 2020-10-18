#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,x,flag,i,j;
    
    cin>>t;
    for(int p=0;p<t;p++){
       
        cin>>n;
        // cout<<"n="<<n<<"\n";
        vector<int> v(n+1,0);
        vector<int> h;
    
        for( i=1;i<=n;++i){
            cin>>x;
            v[max(0,i-x)]+=1;
            if(i+x+1<=n){
                v[i+x+1]-=1;
            }
           }
        int cur=0;   
        for(i=0;i<=n;i++){
            cur+=v[i];
            v[i]=cur;
        }
        v.erase(v.begin());

        sort(v.begin(),v.end());

        for( i=0;i<n;++i){
            cin>>x;
            h.push_back(x);
        }
        sort(h.begin(),h.end());

        flag=0;
        for(i=0;i<n;++i){
            if(h[i]!=v[i]){
                flag=1;break;
            }
        }

        if(flag==1)cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}