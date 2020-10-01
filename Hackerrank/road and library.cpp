#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
vector<int> arr[100005];
bool vis[100005];
vector<int> v;
int dfs(int node){
	vis[node]=true;
	int num_node=0;
	for(int child:arr[node]){
		if(!vis[child])
			num_node+=dfs(child);
	}
	return num_node+1;
}
int main(){
	int t,n,m,cl,cr,a,b;
	cin>>t;
	while(t--){
		cin>>n>>m>>cl>>cr;
		for(int i=1;i<=n;i++) arr[i].clear(),vis[i]=false;
		v.clear();
		for(int i=0;i<m;i++) cin>>a>>b,arr[a].pb(b),arr[b].pb(a);
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				int x=dfs(i);
				v.pb(x);
			}
		}
		ll ans=0;
		for(int i=0;i<v.size();i++){
			ll a=v[i]*cl;
			ll b=(v[i]-1)*cr+cl;
			ans+=min(a,b);
		}
		cout<<ans<<endl;
	}
}
