#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
 
const int mxn = 1e5 + 1;
vector<int> edges[mxn], visi(mxn, 0), v;
 
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
	for(int i = 1; i<=n; ++i){
		if(!visi[i]){
			v.push_back(i);
			dfs(i);
		}
	}
	cout<<v.size() - 1<<endl;
	for(int i = 1; i< v.size(); ++i){
		cout<<v[i]<<" "<<v[i-1]<<endl;
	}
	return 0;
}
