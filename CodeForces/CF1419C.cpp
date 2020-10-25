#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define w(t) \
   int t;    \
   cin >> t; \
   while (t--)
#define fo(i, n) for (int i = 0; i < n; i++)
#define endl "\n"
#define MOD 1000000007
void Tez()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}
int main()
{
   Tez();
   w(q)
   {
      int n, x;
      cin >> n >> x;
      int a[n];
      fo(i, n) cin >> a[i];
      bool f = false;
      int countSick = 0;
      for (int i = 0; i < n; i++)
      {
         if (a[i] != x)
         {
            f = true;
         }
         else
         {
            countSick++;
         }
      }
      if (!f)
      {
         cout << 0 << endl;
         continue;
      }
      if (countSick > 0)
      {
         cout << 1 << endl;
         continue;
      }
      ll change = 0;
      fo(i, n)
      {
         change += (x - a[i]);
      }
      if (change == 0)
      {
         cout << 1 << endl;
      }
      else
      {
         cout << 2 << endl;
      }
   }
   return 0;
}