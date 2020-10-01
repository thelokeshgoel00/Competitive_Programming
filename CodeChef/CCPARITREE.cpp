#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
const int MAXN = (int) 2e5 + 10;

//this problem is a typical dsu/connected component question which includes concept of bicoloring

int visited[MAXN];

long long mypow(long long a,long long b)
{
    if(b==0)
    {
        return 1;
    }
    long long res = 1;
    while(b>0)
    {
        if(b&1)
            res = ((res%mod)*(a%mod))%mod;
        b = b>>1;
        a = ((a%mod)*(a%mod))%mod;
    }
    return res;
}

long long comp;

class graph
{
list<int> *l;
int n;
public:
    graph(int n)
    {
        this->n = n;
        l = new list<int>[n+3];
        //visited = new bool[n+3];
        //memset(bool,0,sizeof(bool));
        
    }
    void addedge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void dfs(int src)
    {
        visited[src] = comp;
        for(auto x:l[src])
        {
            if(!visited[x])
            {
                dfs(x);
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
        int u,v,x,n,q;
        cin>>n>>q;
        //cout<<"n and q is "<<n<<" "<<q<<endl;
        graph g1(n);
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            g1.addedge(u,v);
        }
        /*
        here we will simplify the equation 
        Xu^Xv = x 
        x is given in the question either 0/1 
        if we change the edge weight then no. of value we can give to a particular Xi changes
        So either way we can say that changing the no. of assesment on Xi changes the combination of edge
        weights 
        so our main motive is to find no. of possible assesment on Xi
        two condition are here if x = 0 Xv = Xu and for x = 1 Xu != Xv
        there is also a edge case that if we got a odd cycle then the answer will be 0 
        So we will use bicoloring of the graph
        with 0 marker they are attached to same color 
        with 1 marker they are attached to different color
        So for u,v we will connect their children 2*u,2*u+1,2*v,2*v+1 
        so that bicoloring can happen 
        Now we can observe that for every edge u there is two connected component(for every size no exception here)
        So the final answer is mypow(2,comp/2 - 1);
        similar to mypow(2,c)
        */
        graph g2(2*n);
        while(q--)
        {
            cin>>u>>v>>x;
            //cout<<"u v and x is "<<u<<" "<<v<<" "<<x<<endl;
            u--;
            v--;
            if(x==0)
            {
                //this is bicoloring same color is attached to same color
                g2.addedge(2*u,2*v);
                g2.addedge(2*u+1,2*v+1);
            }
            else if (x==1)
            {
                //this is bicoloring different colors are attached to each other
                g2.addedge(2*u,2*v+1);
                g2.addedge(2*u+1,2*v);
            }
        }
            //now we will count no. of connected component present here 
            comp = 1;
            memset(visited,0,sizeof(visited));
            for(int i=0;i<2*n;i++)
            {
                if(!visited[i])
                {
                    g2.dfs(i);
                    comp++;
                }
            }
            //cout<<"comp is "<<comp<<endl;
            //cout<<"dfs done"<<endl;
            int flag = 1;
            for(int i=0;i<n;i++)
            {
                if(visited[2*i]==visited[2*i+1])
                {
                    flag = 0;
                    break;
                }
            }
            //cout<<"checking done "<<endl;
            if(flag)
            {
                long long ans = mypow(2,(comp/2 -1));
                cout<<ans<<endl;
            }
            else
            {
                cout<<0<<endl;
            }
        
        
    }
}

