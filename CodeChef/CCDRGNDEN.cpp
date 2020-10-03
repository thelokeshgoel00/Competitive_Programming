#include <bits/stdc++.h>
using namespace std;



void buildtree(long long *t,int *a,int *art, int index, int ss, int se) {
    if (ss == se) 
    {
        t[index] = a[art[ss]];
    } 
    else 
    {
        int mid = ss + se;
        mid = mid/2;
        buildtree(t, a, art, index*2, ss, mid);
        buildtree(t, a, art, index*2+1, mid+1, se);
        t[index] = t[index*2] + t[index*2+1];
    }
}

long long sum(long long *t,int index, int ss, int se, int l, int r) {
    if (l > r) 
    {
        return 0;
    }
    if (l == ss && r == se) 
    {
        return t[index];
    }
    int mid = ss + se;
    mid = mid/2;
    int start_point_1 = max(l, mid+1);
    int end_point_1 = min(r, mid);
    return sum(t,index*2, ss, mid, l, end_point_1) + sum(t,index*2+1, mid+1, se, start_point_1, r);
}

void updatetree(long long *t,int index, int ss, int se, int pos, int new_val) 
{
    if (ss == se) 
    {
        t[index] = new_val;
    } 
    else
    {
        int mid = ss + se;
            mid = mid/2;
        if (pos <= mid)
        {
            updatetree(t,index*2, ss, mid, pos, new_val);
        }
        else
        {
            updatetree(t,index*2+1, mid+1, se, pos, new_val);
        }
        t[index] = t[index*2] + t[index*2+1];
    }
}

void buildheight(int *t, int *a, int index, int ss, int se) 
{
    if (ss == se) 
    {
        t[index] = a[ss];
    } 
    else 
    {
        int mid = ss + se;
            mid = mid/2;
        buildheight(t,a, index*2, ss, mid);
        buildheight(t,a, index*2+1, mid+1, se);
        t[index] = max(t[index*2] , t[index*2+1]);
    }
}

int maxheight(int *t,int index, int ss, int se, int l, int r)
{
    if (l > r) 
    {
        return 0;
    }
    if (l == ss && r == se) 
    {
        return t[index];
    }
    int mid = ss + se;
    mid = mid/2;
    int end_point_1 = min(r, mid);
    int start_point_1 = max(l, mid+1);
    return max(maxheight(t,index*2, ss, mid, l, end_point_1), maxheight(t,index*2+1, mid+1, se, start_point_1, r));
}




int main() 
{

        int n,q,x,y,z;
        cin>>n>>q;
        if(n<=2000 && q<=200)
        {
            
            int h[n+3],a[n+3],hrev[n+3],arev[n+3];
            for(int i =1;i<=n;i++)
            {
                cin>>h[i];
            }
            for(int i=1;i<=n;i++)
            {
                cin>>a[i];
            }
            for(int i=1;i<=n;i++)
            {
                hrev[n+1-i]=h[i];
                arev[n+1-i]=a[i];
            }
            while(q--)
            {
                long long ans = 0;
                int int_height = 0;
                int prev_height = 0;
                int prev_max_height = 0;
                long long temp = 0;            
                cin>>x>>y>>z;
                if(x==1)
                {
                    a[y] = z;
                    continue;
                }
                if(y==z)
                {
                    ans = a[y];    
                }
                else if(y<z)
                {
                    ans = 0;
                    int_height = h[y];
                    stack<int> s1;
                    s1.push(y);
                    for(int i=y+1;i<=z;i++)
                    {
                        if(h[i]>=int_height)
                        {
                            ans = -1;
                            while(!s1.empty())
                            {
                                s1.pop();
                            }
                            break;
                        }
                        while(!s1.empty() && h[s1.top()]<=h[i])
                        {
                            s1.pop();
                        }
                        s1.push(i);
                    }
                    while(!s1.empty())
                    {
                        ans += a[s1.top()];
                        s1.pop();
                    }
                    
                }
                else if(y>z)
                {
                    //y = n - y + 1;
                    //z = n - z + 1;
                    ans = 0;
                    int_height = h[y];
                    stack<int> s1;
                    s1.push(y);
                    for(int i=y-1;i>=z;i--)
                    {
                        if(h[i]>=int_height)
                        {
                            ans = -1;
                            while(!s1.empty())
                            {
                                s1.pop();
                            }
                            break;
                        }
                        while(!s1.empty() && h[s1.top()]<=h[i])
                        {
                            s1.pop();
                        }
                        s1.push(i);
                    }
                    while(!s1.empty())
                    {
                        ans += a[s1.top()];
                        s1.pop();
                    }
                }
                cout<<ans<<endl;
            }
        }
        else
        {
            int h[n],a[n],hrev[n],arev[n];
            for(int i =0;i<n;i++)
            {
                cin>>h[i];
            }
            for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
            for(int i=0;i<n;i++)
            {
                hrev[n-1-i]=h[i];
                arev[n-1-i]=a[i];
            }
            int nxt1[n],nxt2[n];
            stack<int> st;
            st.push(n-1);
            nxt1[n-1]=-1;
            for(int i=n-2;i>=0;i--)
            {
                while(!st.empty()&&h[st.top()]<=h[i])
                st.pop();
                if(st.empty())
                nxt1[i]=-1;
                else
                nxt1[i]=st.top();
                st.push(i);
            }
            while(!st.empty())
            {
                st.pop();
            }        
            st.push(n-1);
            nxt2[n-1]=-1;
            for(int i=n-2;i>=0;i--)
            {
                while(!st.empty()&&hrev[st.top()]<=hrev[i])
                    st.pop();
                if(st.empty())
                    nxt2[i]=-1;
                else
                    nxt2[i]=st.top();
                st.push(i);
            }        
            int g2[n],g1[n],art[n],nwidxl[n],enl[n]={0},art2[n],nwidxl2[n],enl2[n]={0};
            set <int> l1;
            for(int i=0;i<n;i++)
            {
                l1.insert(i);
            }
            z=0;x=0,y=0;
            while(l1.size()!=0)
            {
                if(l1.find(z)!=l1.end())
                {
                    l1.erase(z);
                    art[y]=z;
                    nwidxl[z]=y;
                    enl[x]=y;
                    y++;
                    g1[z]=x;
                    z=nxt1[z];
                    if(l1.size()!=0&&z==-1)
                    {
                        z=*l1.begin();
                        x++;
                    }
                 
                }
                else if(l1.size()!=0)
                {
                    z=*l1.begin();
                    x++;
                }
            }
            l1.clear();
            for(int i=0;i<n;i++)
            {
                l1.insert(i);
            }
            z=0;x=0,y=0;
            while(l1.size()!=0)
            {
                if(l1.find(z)!=l1.end())
                {
                    l1.erase(z);
                    art2[y]=z;
                    nwidxl2[z]=y;
                    enl2[x]=y;
                    y++;
                    g2[z]=x;
                    z=nxt2[z];
                    if(l1.size()!=0&&z==-1)
                    {
                        z=*l1.begin();
                        x++;
                    }
                }
                else if(l1.size()!=0)
                {
                    z=*l1.begin();
                    x++;
                }
               
            }
        
        
        
        long long sumright[4*n+4]={0},sumright2[4*n+4]={0};
        buildtree(sumright,a,art,1,0,n-1);
        buildtree(sumright2,arev,art2,1,0,n-1);
        int t[4*n+4] = {0};    
        buildheight(t,h,1,0,n-1);    
            while(q--)
            {
                cin>>x>>y>>z;
                long long ans=0;
                bool f=false;
                y--;z--;
                if(x==1)
                {
                    updatetree(sumright,1,0,n-1,nwidxl[y],z+1);
                    updatetree(sumright2,1,0,n-1,nwidxl2[n-1-y],z+1);
                    a[y]=z+1;
                }
                else if(h[y]<=h[z]&&y!=z)
                {
                    cout<<-1<<endl;
                }
                else if(y==z)
                {
                    cout<<a[y]<<endl;
                }
                else if(y<z)
                {
                    if(maxheight(t,1,0,n-1,y+1,z)>=h[y])
                    {
                        ans=-1;
                    }
                    else
                    {
                        long long c1=0;
                        z=n-1-z;
                        y=n-1-y;
                        while(1)
                        {    
                            if(enl2[g2[y]]!=enl2[g2[z]])   
                            {
                                c1+=sum(sumright2,1,0,n-1,nwidxl2[z],enl2[g2[z]]);
                            }
                            else
                            {
                                c1+=sum(sumright2,1,0,n-1,nwidxl2[z],nwidxl2[y]);   
                                break;
                            }
                            z=nxt2[art2[enl2[g2[z]]]];
                            if(z==-1)
                            {
                                break;
                            }
                        } 
                        ans=c1;
                    }
                    cout<<ans<<endl;   
                }
                else
                {
                    if(maxheight(t,1,0,n-1,z,y-1)>=h[y])
                    {
                     ans=-1;
                    }
                    else
                    {
                        long long c1=0;  
                        while(1)
                        {    
                            if(enl[g1[y]]!=enl[g1[z]])
                            {
                                c1+=sum(sumright,1,0,n-1,nwidxl[z],enl[g1[z]]);   
                            }
                            else
                            {
                                c1+=sum(sumright,1,0,n-1,nwidxl[z],nwidxl[y]);   
                                break;
                            }
                            z=nxt1[art[enl[g1[z]]]];
                            if(z==-1)
                            {
                                break;
                            }
                        } 
                       ans=c1;
                    } 
                    cout<<ans<<endl;   
                }
            }
        }
}
