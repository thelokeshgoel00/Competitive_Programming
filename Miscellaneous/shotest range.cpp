#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector<int> arr[10000005];
bool vis[10000005];
ll dist[10000005];
void bfs(int node){
	vis[node]=true;
    dist[node]=0;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int child:arr[x]){
            if(!vis[child]){
                vis[child]=true;
                dist[child]=dist[x]+6;
                q.push(child);
            }
        }
    }
}
int main(){
    int t,n,m,a,b;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) arr[i].clear(),vis[i]=false;
        for(int i=0;i<m;i++){
            cin>>a>>b,arr[a].pb(b),arr[b].pb(a);
        }
        int start;
        cin>>start;
        memset(dist,-1,(n+1)*sizeof(dist[0]));
        bfs(start);
        for(int i=1;i<=n;i++){
            if(i!=start){
                cout<<dist[i]<<" ";
            }
        }
        cout<<endl;
    }
}

