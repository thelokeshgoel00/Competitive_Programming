#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fin for(int i=0;i<n;i++)
#define ff first
#define ss second
#define vi vector<int>
#define vc vector<char>
#define vii vector<int,int>
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL) 
vector<int> arr[10001];
set<int>AP;
int vis[10001],in[10001],low[10001],timer;
void dfs(int node,int parent=-1){
	vis[node]=1;
	int children=0;
	in[node]=low[node]=timer++;
	for(int child:arr[node]){
		if(child==parent)continue;
		else if(vis[child])
			low[node]=min(low[node],in[child]);
		else{
			dfs(child,node);
			low[node]=min(low[node],low[child]);
			if(low[child]>=in[node]&&parent!=-1)
				AP.insert(node);
			children++;
		}
	}
	if(parent==-1&&children>1)
		AP.insert(node);
}
int main(){
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n,m,a,b;
    while(1){
    	cin>>n>>m;
    	if(n==0&&m==0)
    		break;
    	for(int i=1;i<=n;i++)
    		arr[i].clear(),vis[i]=0;
    	AP.clear();
    	timer=1;
    	for(int i=0;i<m;i++){
    		cin>>a>>b,arr[a].pb(b),arr[b].pb(a);
    	}
    	for(int i=1;i<=n;i++){
    		if(vis[i]==0)
    			dfs(i);
    	}
    	cout<<AP.size()<<endl;
    }
    return 0;
}