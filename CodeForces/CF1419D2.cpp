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
   int n;
   cin >> n;
   int a[n];
   fo(i, n) cin >> a[i];
   sort(a, a + n);
   vector<int> res(n);
   int j = 1;
   for (int i = 0; i < n / 2; i++)
   {
      res[j] = a[i];
      j += 2;
   }
   j = 0;
   for (int i = n / 2; i < n; i++)
   {
      res[j] = a[i];
      j += 2;
   }
   ll ans = 0;
   for (int i = 1; i < n - 1; i++)
   {
      if (res[i] < res[i - 1] && res[i] < res[i + 1])
      {
         ans++;
      }
   }
   cout << ans << endl;
   fo(i, n) cout << res[i] << " ";
   return 0;
}
