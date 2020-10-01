#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int *dp;

/*
	This problem is based on - modification of DFS
*/

class graph
{
list<int>*l;
bool *visited;

int n;
public:
    graph(int n)
    {
        this->n = n;
        l = new list<int>[n+5];
        dp = new int[n+5];
        visited = new bool[n+5];
        memset(visited,false,sizeof(visited));
        memset(dp,0,sizeof(dp));
    }
    void addedges(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    int dfs(int src)
    {
        visited[src] = true;
        if(l[src].size()==1)//if it's the leaf node we will set dp as 1
        {
            dp[src] = 1;
            return 1;
        }
        if(dp[src]!=0)//if dp is not empty we will return it
        {
            return dp[src];
        }
        int ans = 0;
        for(auto x:l[src])
        {
            if(!visited[x])
            {
                ans+= dfs(x);
            }
        }
        //value of dp
        ans = ans + 1;
        dp[src] = ans;
        return ans;
    }

};

int main(void)
{
    fastio;
    int n,m,x,y;
    cin>>n;
    graph g(n);
    cin>>m>>x;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        g.addedges(x,y);
    }
    g.dfs(1);
    for(int i=2;i<=n;i++)
    {
        cout<<((n-dp[i])*dp[i])<<endl;
    }




}
