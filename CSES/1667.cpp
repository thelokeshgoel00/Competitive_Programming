#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
 
const int mxn = 1e5 + 1;
vector<int> edges[mxn], visi(mxn, -1), par(mxn, -1);
 
void dfs(int x){
	visi[x] = 1;
	for(auto u : edges[x]){
		if(visi[u]==0){
			dfs(u);
		}
	}
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin>>n>>m;
	for(int i = 0; i < m; ++i){
		int x, y;cin>>x>>y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	queue<int> q;
	q.push(1);
	visi[1] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto x : edges[u]){
			if(visi[x]!=-1) continue;
			visi[x] = visi[u] + 1;
			par[x] = u;
			q.push(x);
		}
	}
	if(visi[n]==-1){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	cout<<visi[n] + 1<<endl;
	vector<int> v;
	int p = n;
	v.push_back(p);
	while(par[p]!=-1){
		p  = par[p];
		v.push_back(p);
	}
	reverse(v.begin(), v.end());
	for(auto x : v){
		cout<<x<<" ";
	}
	return 0;
}
