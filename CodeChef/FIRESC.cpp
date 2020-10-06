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
#define mod 1000000007
int vis[100005];
vi ar[100005];
int cc_size;
void dfs(int node){
	vis[node]=1;
	cc_size++;
	for(int child:ar[node])
		if(vis[child]==0)
			dfs(child);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
    	int n,m,a,b;
    	cin>>n>>m;
    	for(int i=1;i<=n;i++) vis[i]=0,ar[i].clear();
    	for(int i=1;i<=m;i++) cin>>a>>b , ar[a].pb(b),ar[b].pb(a);
    	int cnt=0; 
    	ll res=1;
    	for(int i=1;i<=n;i++){
    		if(vis[i]==0){
    			cc_size=0;
    			dfs(i),cnt++;
    			res=(res*cc_size) % mod;
    		}
    	}
    	cout<<cnt<<" "<<res<<endl;
    }
    return 0;
}