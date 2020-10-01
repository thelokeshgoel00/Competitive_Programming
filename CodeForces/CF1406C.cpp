#include<bits/stdc++.h>
using namespace std;
#define ll int long long
#define mp make_pair
//#define for(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define N 1000000007
#define pq priority queue
#define pb push_back
#define pf push_front
#define mt make_tuple
#define prec(a) fixed<<setprecision(9)<<a
#define endl "\n"
#define fast_set s.max_load_factor(0.25);s.reserve(500);
#define cy cout<<"YES"<<endl;
#define cn cout<<"NO"<<endl;
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
const long double PI = (long double)(3.1415926535897932384626433832795);

// Depth first search also calculating size of all subtrees
void dfs(int s,int siz[],vector<int > adj[],int par[],int vis[],int parent){
	vis[s]=1;
	par[s]=parent;
	siz[s]=1;

	// traversing all adjacent elements
	for(auto it:adj[s])
	{
		if(!vis[it])
		{
			dfs(it,siz,adj,par,vis,s);
			siz[s]+=siz[it];
		}
	}
}

// another depth first search but this time to find reachable element(not size).
void dfs1(int s,int vis[],vector<int>adj[],int par[],int p)
{
	vis[s]=1;
	//assigning parent p to s.
	par[s]=p;

	//traversing all adjacent elements.
	for(auto it:adj[s])
	{
		if(!vis[it])
		{
			dfs1(it,vis,adj,par,s);
			
		}
	}
}
int main() 
{
	fast;
	int test,n,i,j,k;
	cin>>test;

	// for all testcases
	while(test--)
	{
		cin>>n;
		int u,v;

		// to store all adjacencies
		vector<int>adj[n+1];

		// to store all edges
		vector<pair<int,int>>edges;
		for(i=1;i<n;i++)
		{
			cin>>u>>v;
			edges.pb(mp(u,v));
			adj[u].pb(v);
			adj[v].pb(u);
		}

		// siz represents size of subtrees array.
		int siz[n+1]={0};

		// par represents parent array
		int par[n+1];
		int vis[n+1]={0};
		memset(par,-1,sizeof(par));
		dfs(1,siz,adj,par,vis,-1);
		bool flag=true;
		for(auto it:edges)
		{
			u=it.F;
			v=it.S;
			int siz1=0,siz2=0;
			if(par[u]==v)
			{
				siz1=siz[u];
				siz2=n-siz1;
			}
			else
			{
				siz2=siz[v];
				siz1=n-siz2;

			}
			if(siz1==siz2)
			{
				
				flag=false;
				break;
			}
		}

		// flag is true if there is no edge connecting two components of equal sizes.
		if(flag)
		{
			cout<<edges[0].F<<" "<<edges[0].S<<endl;
			cout<<edges[0].F<<" "<<edges[0].S<<endl;
		}
		else
		{
			
			memset(vis,0,sizeof(vis));
			memset(par,-1,sizeof(par));
			vis[v]=1;
			dfs1(u,vis,adj,par,-1);
			int leaf=-1;
			for(i=1;i<=n;i++)
			{
				if(i!=v&&vis[i]&&adj[i].size()==1)
				{
					leaf=i;
					break;
				}
			}
			cout<<par[leaf]<<" "<<leaf<<endl;
			cout<<leaf<<" "<<v<<endl;
		}

	}
	return 0;
}