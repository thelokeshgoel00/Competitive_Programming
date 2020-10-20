#include<bits/stdc++.h>
using namespace std;



int main()
{
  int t;
  cin>>t;
  int perms[8][3]={{0,0,0},
                   {0,0,1},
                   {0,1,1},
                   {1,1,1},
                   {1,1,0},
                   {1,0,0},
                   {1,0,1},
                   {0,1,0}
                 };

  for(int i=0;i<t;++i)
  {
    string str[2];
    cin>>str[0]>>str[1];
    int flag=0;
    for(int p=0;p<8;p++)
    {
      int b=0,o=0;
      //string perm;
      if(str[perms[p][0]][0]=='b')
      ++b;
      if(str[perms[p][0]][0]=='o')
      ++o;
      if(str[perms[p][1]][1]=='b')
      ++b;
      if(str[perms[p][1]][1]=='o')
      ++o;
      if(str[perms[p][2]][2]=='b')
      ++b;
      if(str[perms[p][2]][2]=='o')
      ++o;
      if(b==2 && o==1)
      {
        cout<<"yes\n";
        flag=1;
        break;
      }
    }
    if(flag==0)
    {
      cout<<"no\n";
    }
  }
  return 0;
}
