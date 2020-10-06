
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

int main()
{

   int n;
   cin >> n;
   ll dp[2][4];
   dp[0][3] = 1;
   for (int i = 0; i < 3; i++)
      dp[0][i] = 0;
   for (int i = 0; i < 4; i++)
      dp[1][i] = 0;
   for (int ind = 1; ind <= n; ind++)
   {
      for (int j = 0; j < 4; j++)
      {
         for (int k = 0; k < 4; k++)
         {
            if (k != j)
               dp[1][j] = (dp[1][j] + dp[0][k]) % MOD;
         }
      }
      for (int i = 0; i < 4; i++)
      {
         dp[0][i] = dp[1][i];
         dp[1][i] = 0;
      }
   }
   cout << dp[0][3] << endl;
   return 0;
}
