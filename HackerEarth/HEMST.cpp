#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

/*
this is based on maximum spanning tree
this is done by modifying kruskal algorithm
we will made our custom sort function to sort them in Increasing Order
*/

class dsu
{
int *parent;
int *rank;
public:
    dsu(int n)
    {
        parent = new int[n+5];
        rank = new int[n+5];
        for(int i=0;i<=n;i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    int find(int i)
    {
        if(parent[i]==-1)
        {
            return i;
        }
        return parent[i] = find(parent[i]);//path compression
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
                rank[s2] += rank[s1];    
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

//custom sort function
bool compare(vector<int> a,vector<int > b)
{
    return (a[0]>b[0]);
}

class graph
{
vector<vector<int>>edgeList;
int n;
public:
    graph(int n)
    {
        this->n = n;
    }
    void addedge(int x,int y,int w)
    {
        edgeList.push_back({w,x,y});
    }

    int kruskal_mst()
    {
        sort(edgeList.begin(),edgeList.end(),compare);
        int ans = 0;
        dsu s(n);
        for(auto edge:edgeList)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            if(s.find(x)!=s.find(y))
            {
                s.unite(x,y);
                ans+= w;
            }
        }
        return ans;
    }
};

int main(void)
{
    fastio;
    int t;
    cin>>t;
    int x,y,w;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        graph g(n);
        for(int i=0;i<m;i++)
        {
            cin>>x>>y>>w;
            g.addedge(x,y,w);
        }
        cout<<g.kruskal_mst()<<endl;
    }
    
}











