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
int vis[100001],in[100001],low[100001],timer;
vector<int>arr[100001];
vector<pair<int,int> >edgelist;
bool isBridge;
void dfs(int node,int parent){
	vis[node]=1;
	in[node]=low[node]=timer++; 
	for(int child:arr[node]){
		if(child==parent)continue;
		else if(vis[child]){
			//therefore it is a back edge
			low[node]=min(low[node],in[child]);
			if(in[node]>in[child])
				edgelist.pb({node,child});
		}
		else{
			dfs(child,node);
			if(low[child]>in[node]){
				isBridge=true;
				return;
			}
			edgelist.pb({node,child});
			low[node]=min(low[node],low[child]);
		}
	}
}
int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n,m,a,b;
    cin>>n>>m;
    while(m--){
    	cin>>a>>b;
    	arr[a].pb(b),arr[b].pb(a);
    }
    dfs(1,-1);
    if(isBridge)
    	cout<<0<<endl;
    else{
    	for(pair<int,int> e : edgelist)
    		cout<<e.first<<" "<<e.second<<endl;
    }
    return 0;
}