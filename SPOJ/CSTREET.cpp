#include<bits/stdc++.h>
using namespace std;
#define int long long
 
/*
IF we simplify this problem then it converts to finding minimum spanning tree 
and then we multiply the value of given street
*/ 
 
class DSU
{
int *parent;
int *rank;
int n;
public:
    DSU(int n)
    {
        this->n = n;
        parent = new int[n+2];
        rank = new int[n+2];
        for(int i=0;i<=n;i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    int find(int x)
    {
        if(parent[x]==-1)
        {
            return x;
        }
        return parent[x] = find(parent[x]);//path compression
    }
    void unite(int x,int y)
    {
        int s1 = find(x);
        int s2 = find(y);
        if(s1!=s2)
        {
        	//union by rank
            if(rank[s1]<rank[s2])
            {
                parent[s1] = s2;
                rank[s2]+= rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1]+= rank[s2];
            }
        }
    }
};
 
class graph
{
vector<vector<int>> edgelist;
int n;
public:
    graph(int n)
    {
        this->n = n;
    }
    void addedge(int x,int y,int w)
    {
        edgelist.push_back({w,x,y});
    }
    int mst()
    {
        sort(edgelist.begin(),edgelist.end());
        long long ans = 0;
        DSU d(n);
        for(auto edge:edgelist)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            if(d.find(x) != d.find(y))
            {
                ans+= w;
                d.unite(x,y);
            }
        }
        return ans;
    }
    
};
 
 
signed main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        int p,n,m;
        cin>>p>>n>>m;
        graph g(n);
        for(int i=0;i<m;i++)
        {
            int x,y,w;
            cin>>x>>y>>w;
            g.addedge(x,y,w);
        }
        long long ans = g.mst();
        ans = ans*p;
        cout<<ans<<endl;
    }
    
}
