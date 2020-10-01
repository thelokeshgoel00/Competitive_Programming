#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
vector<int>arr[100005];
bool vis[100005];
ll sum[100005];
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
	int n,m,a,b;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b,arr[a].pb(b),arr[b].pb(a);
	}
	int cc=0;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			int x=dfs(i);
			cc++;
			if(cc-1==0)
				sum[cc-1]=x;
			else
				sum[cc-1]=x+sum[cc-2];
		}
	}
	ll ans=0;
	for(int i=cc-1;i>0;i--){
		ll a=sum[i]-sum[i-1];
		ll b=sum[i-1];
		ans+=a*b;
	}
	cout<<ans<<endl;
}
