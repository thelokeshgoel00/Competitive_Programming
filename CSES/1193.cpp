#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
 
const int mxn = 1e3 + 1;
int visi[mxn][mxn];
pair<int, int> par[mxn][mxn];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
int n, m;
string s[mxn];
void dfs(int x, int y, int level, int px, int py){
	visi[x][y] = level;
	par[x][y] = {px, py};
	for(int i= 0; i < 4; ++i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx>=0 && nx < n && ny>=0 && ny < m && visi[nx][ny] == -1 && s[nx][ny]!='#'){
			dfs(nx, ny, level + 1, x, y);
		}
	}
}
 
void bfs(int x, int y){
	queue<pair<int, int>> q;
	q.push({x, y});
	visi[x][y] = 0;
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			if(nx>=0 && nx < n && ny>=0 && ny < m && visi[nx][ny] == -1 && s[nx][ny]!='#'){
				visi[nx][ny] = visi[p.first][p.second] + 1;
				par[nx][ny] = {p.first, p.second};
				q.push({nx, ny});
			}
		}
	}
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	int cnt = 0;
	for(int i = 0; i < n; ++i) cin>>s[i];
	pair<int, int> p[2];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(s[i][j]=='A'){
				p[0] = {i, j};
			} if(s[i][j]=='B'){
				p[1] = {i, j};
			}
			visi[i][j] = -1;
			par[i][j] = {visi[i][j], visi[i][j]};
		}
	}
	bfs(p[0].first, p[0].second);
	int val = visi[p[1].first][p[1].second];
	if(val==-1){
		cout<<"NO\n";
	} else{
		cout<<"YES\n";
		cout<<val<<endl;
		string s = "";
		pair<int, int> px = p[1], p = {(int)-1, (int)-1};
		while(par[px.first][px.second] != p){
			pair<int, int> temp = par[px.first][px.second];
			if(temp.second == px.second){
				if(temp.first + 1 == px.first){
					s += 'D';
				}else{
					s += 'U';
				}
			} else{
				if(temp.second + 1 == px.second){
					s += 'R';
				} else{
					s += 'L';
				}
			}
			px = temp;
		}
		reverse(s.begin(), s.end());
		cout<<s<<endl;
	}
	return 0;
}
