#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
 
const int mxn = 1e3 + 1;
int visi[mxn][mxn];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
int n, m;
string s[mxn];
void dfs(int x, int y){
	visi[x][y] = 1;
	for(int i= 0; i < 4; ++i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx>=0 && nx < n && ny>=0 && ny < m && !visi[nx][ny] && s[nx][ny]=='.'){
			dfs(nx, ny);
		}
	}
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	memset(visi, 0, sizeof(visi));
	int cnt = 0;
	for(int i = 0; i < n; ++i) cin>>s[i];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(!visi[i][j] && s[i][j]=='.'){
				dfs(i, j);
				//cout<<i<<" "<<j<<endl;
				++cnt;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
