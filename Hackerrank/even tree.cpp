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
vector<int> arr[105];
int ans=0;
bool vis[105];
int dfs(int node){
	vis[node]=true;
	int num_vertex=0;
	for(int child:arr[node]){
		if(!vis[child]){
			int num_node=dfs(child);
			if(num_node%2==0)
				ans++;
			else
				num_vertex+=num_node;
		}
	}
	return num_vertex+1;
}
int main(){
    FASTIO;
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
    	cin>>a>>b,arr[a].pb(b),arr[b].pb(a);
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}