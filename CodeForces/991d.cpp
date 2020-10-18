#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long int lli;
using namespace std;

char up[101],low[101];
int main()
{
  cin>>up;
  cin>>low;
  int b=0;
  loop(i,0,100)
    {
      if(up[i]=='0' && low[i]=='0')
      {
        if(i>0)
        {
          if(up[i-1]=='0')
          {
            b++;
            up[i]=low[i]=up[i-1]='X';
            continue;
          }
          else if(low[i-1]=='0')
          {
            b++;
            up[i]=low[i]=low[i-1]='X';
            continue;
          }
        }
        if(up[i+1]=='0')
        {
          b++;
          up[i]=low[i]=up[i+1]='X';
          continue;
        }
        if(low[i+1]=='0')
        {
          b++;
          up[i]=low[i]=low[i+1]='X';
          continue;
        }
      }
    }  
  cout<<b<<endl;
  return 0;
}
