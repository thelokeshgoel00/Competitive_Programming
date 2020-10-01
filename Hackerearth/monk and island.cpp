#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
vi arr[10001];
int vis[10001];
int dist[10001];
void bfs(int node){
    vis[node]=1;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int parent=q.front();
        q.pop();
        for(int child:arr[parent]){
            if(vis[child]==0){
                vis[child]=1;
                q.push(child);
                dist[child]=dist[parent]+1;
				cout<<child<<" "<<dist[child]<<endl;
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,a,b;
        cin>>n>>m;
        for(int i=1;i<=n;i++) vis[i]=0,arr[i].clear();

        for(int i=0;i<m;i++){
            cin>>a>>b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        bfs(1);
        cout<<dist[n]<<endl;
    }
}
