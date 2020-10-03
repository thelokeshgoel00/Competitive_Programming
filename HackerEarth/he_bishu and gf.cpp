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
vi ar[1001];
int vis[1001],dist[1001];
void dfs(int node ,int d){
	vis[node]=1;
	dist[node]=1;

	for(int child: ar[node]){
		if(vis[child]==0){
			dfs(child,dist[node]+1);
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
        int n,a,b,q,i=0;
        cin>>n;
        while(i<n-1){
        	cin>>a>>b;
        	ar[a].pb(b);
        	ar[b].pb(a);
        	i++;
        }

        cin>>q;
        int ans=-1;
        intmin_dist=10000000;
        while(q--){
        	int gc;
        	cin>>gc;
        	if(dist[gc]<min_dist){
        		min_dist=dist[gc],ans=gc;
        	}
        	else{
        		if(dist[gc]==min_dist&&gc<ans)
        			ans=gc;
        	}
        }
        cout<<ans;	
    }