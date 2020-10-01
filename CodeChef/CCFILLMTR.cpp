#include<bits/stdc++.h>
using namespace std;

string ans("yes");

/*
this question is based on bipartite graph and disjoint union sets
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
        parent = new int[n+3];
        rank = new int[n+3];
        for(int i=0;i<=n+1;i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int find(int i)
    {
        if(i==parent[i])
        {
            return i;
        }
        return parent[i] = find(parent[i]);//path compression
    }
    void unite(int x,int y)
    {
        int s1 = find(x);
        int s2 = find(y);
        //cout<<"in unite s1 and s2 is "<<s1<<" "<<s2<<endl;
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

bool *visited;

class graph
{
int *color;
list<int> *l;
int n;
public:
    graph(int n)
    {
        this->n = n;
        visited = new bool[n+3];
        color = new int[n+3];
        l = new list<int>[n+3];
        memset(visited,0,sizeof(visited));
        memset(color,0,sizeof(color));
    }
    void addedge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void dfs(int src,int mycolor)
    {
        color[src] = mycolor;
        visited[src] = true;
        //cout<<"current src is "<<src<<endl;
        for(auto x:l[src])
        {
            if(!visited[x])
            {
                dfs(x,1-mycolor);
            }
            else
            {
                if(color[x] == color[src])
                {
                   // cout<<"x src and color is "<<x<<" "<<src<<" "<<color[x]<<endl;
                    ans = "no";
                }
            }
        }
    }


};

int main(void)
{
    int t;
    cin>>t;
    
    while(t--)
    {
        ans = "yes";
        
        //cout<<"1. current value of ans is "<<ans<<endl;
        vector<pair<int,int>>arr;
        arr.clear();
        int n,q;
        cin>>n>>q;
        graph g(n);
        DSU d(n);
        int x,y,parity;
        //cin>>x>>y>>parity;
        for(int i=0;i<q;i++)
        {
            
            cin>>x>>y>>parity;
            //cout<<"x and y and parity is "<<x<<" "<<y<<" "<<parity<<endl;
            if(x==y)
            {
                if(parity)
                {
                    ans = "no";
                }
            }
            /*
			So main concept here is if parity = 0 then we will unite the components
			and if they are unequal we will create graph from them
			THE main problem here is to prevent odd edge graph so we will use Bipartite graph
			*/
            else if(parity==0)
            {
                d.unite(x,y);
            }
            else if(parity==1)
            {
                arr.push_back(make_pair(x,y));
            }
           // cout<<"2. current value of ans is "<<ans<<endl;
        }
        for(auto val:arr)
        {
           // cout<<"val.first and val.second "<<val.first<<" "<<val.second<<endl;
            int s1 = d.find(val.first);
            int s2 = d.find(val.second);
            //cout<<"s1 and s2 is "<<s1<<" "<<s2<<endl;
            if(s1==s2)
            {
                ans = "no";  
                break;
            }
            g.addedge(val.first,val.second);
           // cout<<"3. current value of ans is "<<ans<<endl;
        }
        memset(visited,false,sizeof(visited));
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                g.dfs(i,0);
            }
        }
        cout<<ans<<endl;
    }
}

