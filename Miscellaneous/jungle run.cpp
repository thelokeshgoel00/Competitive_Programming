#include<bits/stdc++.h>
using namespace std;
char arr[31][31];
bool vis[31][31];
int dist[31][31];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int n;
bool isValid(int x,int y){
	if(x<1||x>n||y<1||y>n) return false;
	if(arr[x][y]=='T'||vis[x][y]==true) return false;
	return true;
}
void bfs(int x,int y){
	queue<pair<int,int> > q;
	vis[x][y]=true;
	dist[x][y]=0;
	q.push({x,y});
	while(!q.empty()){
		int nodex=q.front().first;
		int nodey=q.front().second;
		int d=dist[nodex][nodey];
		q.pop();
		for(int i=0;i<4;i++){
			if(isValid(nodex+dx[i],nodey+dy[i])){
				dist[nodex+dx[i]][nodey+dy[i]]=d+1;
				vis[nodex+dx[i]][nodey+dy[i]]=true;
				q.push({nodex+dx[i],nodey+dy[i]});
			}
		}
	}
}
int main(){
	cin>>n;
	int srcx,srcy,endx,endy;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>arr[i][j];
			if(arr[i][j]=='S') srcx=i,srcy=j;
			if(arr[i][j]=='E') endx=i,endy=j;
		}
	}
	bfs(srcx,srcy);
	cout<<dist[endx][endy]<<endl;
}
