#include<iostream>
using namespace std;
int n,m;
char arr[1001][1001];
bool vis[1001][1001];
bool isValid(int i,int j){
	if(i<0||i>n-1||j<0||j>m-1)
		return false;
	if(vis[i][j]==true||arr[i][j]=='#')
		return false;
	return true;
}
void dfs(int i,int j){
	vis[i][j]=true;
	if(isValid(i-1,j))
		dfs(i-1,j);
	if(isValid(i,j+1))
		dfs(i,j+1);
	if(isValid(i+1,j))
		dfs(i+1,j);
	if(isValid(i,j-1))
		dfs(i,j-1);
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(vis[i][j]==false&&arr[i][j]=='.')
				dfs(i,j),count++;
		}
	}
	cout<<count<<endl;
}
