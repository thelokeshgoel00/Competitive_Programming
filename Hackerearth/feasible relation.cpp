#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fin for(int i=0;i<n;i++)
#define ff first
#define ss second
#define vi vector<int>
#define vc vector<char>
#define vii vector<pair<int,int> >
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL) 
vi arr[1000001];
int vis[1000001];
int cc[1000001];
int cc_node;
void dfs(int node){
	vis[node]=1;
	cc[node]=cc_node;
	for(int child:arr[node]){
		if(vis[child]==0)
			dfs(child);
	}
}
int main(){
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t,n,k,var1,var2;
   	string op;
    cin>>t;
    while(t--){
    	cin>>n>>k;
    	for(int i=1;i<=n;i++) arr[i].clear(),vis[i]=0;
    	vii vec;
    	for(int i=1;i<=k;i++){
    		cin>>var1>>op>>var2;
    		if(op=="="){
    			arr[var1].pb(var2),arr[var2].pb(var1);
    		}
    		else{
    			vec.pb({var1,var2});
    		}
    	}
    	cc_node=1;
    	for(int i=1;i<=n;i++){
    		if(vis[i]==0)
    			dfs(i),cc_node++;
    	}
    	int flag=0;
    	for(int i=0;i<vec.size();i++){
    		int a=vec[i].ff,b=vec[i].ss;
    		if(cc[a]==cc[b]){
    			flag=1;
    			break;
    		} 
    	}
    	if(flag==1)
    		cout<<"NO"<<endl;
    	else
    		cout<<"YES"<<endl;
    }
    return 0;
}