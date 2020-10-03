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
vi arr[1001];
int day[1001];
int P[1001];
int A[1001];
int B[1001];
int vis[1001];
int days;
void bfs(int node){
    vis[node]=1;
    queue<int>q;
    q.push(node);
    B[node]-=min(B[node],A[node]);
	if(B[node]==0)
        day[node]=days;
    else 
       	day[node]=-1;    
    cout<<B[node]<<" "<<node<<" "<<days<<endl;
    while(!q.empty()){
        int parent=q.front();
        q.pop();
        for(int child:arr[parent]){
            if(vis[child]==0){
                vis[child]=1;
                q.push(child);
                B[child]-=min(A[node],B[child]);
                cout<<B[child]<<" "<<child<<" "<<days<<endl;
                if(B[child]==0)
                	day[child]=days;
                else 
                	day[child]=-1;
            }
        }
    }
}
int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t,n,a,b;
    cin>>t;
    while(t--){
    	days=1;
    	cin>>n;
    	for(int i=0;i<n-1;i++)
    		cin>>a>>b,arr[a].pb(b),arr[b].pb(a);
    	fin cin>>P[i];
    	fin cin>>A[i];
    	fin cin>>B[i];
    	for(int i=0;i<n;i++){
    		for(int m=0;m<=n;m++) vis[i]=0;
    		bfs(P[i]);
    		days++;
    		arr[P[i]].clear();
    		for(int j=0;j<n;j++){
    			for (int k=0; k<arr[P[j]].size(); k++) { 
        			if (arr[j][k] == P[i]) {
        				cout<<arr[j][k]<<endl;
            			arr[j].erase(arr[j].begin()+k);
            			break;  
        			}
    			}
    		}
    	}
    	for(int i=0;i<n;i++)
    		cout<<day[P[i]]<<" ";
    	cout<<endl;
    }
    return 0;
}