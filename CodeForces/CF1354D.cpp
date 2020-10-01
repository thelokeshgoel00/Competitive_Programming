#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define vec vector
#define psb push_back
#define fst first
#define scd second
#define ins insert
#define ques 998244353
using namespace std;
#define pii 3.14159265358979323846264338327950288419716939937510
#define rep(i,a,b) for(int i=(a);i<(b);i++)
const int mx=1e6+10;
ll mod=1000000007;const int maxi=1000001;
int bit[maxi+2]={0};
void fenwick_tree_1(int x, int val)
{
  for(;x<=maxi; x += x & -x)
    bit[x] += val;
}
int fenwick_tree_2(int x)
{
  int cnt = 0;
  for(;x>0; x -= x & -x)
    cnt += bit[x];
  return cnt;
}
int bin_search(int y)
{
  int l = 1, r = maxi, ans = -1;
  while(l <= r)
  {
    int mid = l + r >> 1;
    if(fenwick_tree_2(mid) < y)
	{
      l = mid + 1;
    } 
	else
	{
      ans = mid;
      r = mid - 1;
    }
  }
  return ans;
}
void solution()
{
}
// Driver Code
int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	
  int q,n;
  cin>>n>>q;
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    fenwick_tree_1(x,1);
  }
  vector<pair<int,int>>vp;
  set<int>st;
  for(int i=0;i<q;i++)
  {
    int y;
    cin>>y;
    vp.push_back({y,i});
  }
  int ar[q+1]={0};
  for(int i=0;i<q;i++)
  {
    if(vp[i].first>0)
      fenwick_tree_1(vp[i].first,1);
    else
	{
      int value=bin_search(-vp[i].first);
      fenwick_tree_1(value,-1);
    }
  }
  int value=bin_search(1);
  if(value!=-1)
      cout<<(value)<<'\n';
  else
    cout<<0<<endl;
	return 0;
}
