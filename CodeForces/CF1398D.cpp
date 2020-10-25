#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;
int dp[201][201][201];
// This method returns the max area of rectangles we can create.
//here dp[r][g][b]=Max total area of rectangles having r pair of red sticks,g  pair of green sticks,b pair of blue sticks.
int maxArea(vector<int> &R, vector<int> &G, vector<int> &B, int r, int g, int b)
{
    if ((r == 0 && g == 0) || (r == 0 && b == 0) || (b == 0 && g == 0))
        return 0;
    if (dp[r][g][b] != -1)
        return dp[r][g][b];
    if (r == 0)
        return dp[r][g][b] = G[g - 1] * B[b - 1] + maxArea(R, G, B, r, g - 1, b - 1);
    if (g == 0)
        return dp[r][g][b] = R[r - 1] * B[b - 1] + maxArea(R, G, B, r - 1, g, b - 1);
    if (b == 0)
        return dp[r][g][b] = G[g - 1] * R[r - 1] + maxArea(R, G, B, r - 1, g - 1, b);

    return dp[r][g][b] = max(G[g - 1] * B[b - 1] + maxArea(R, G, B, r, g - 1, b - 1),
                         max(R[r - 1] * B[b - 1] + maxArea(R, G, B, r - 1, g, b - 1),
                           G[g - 1] * R[r - 1] + maxArea(R, G, B, r - 1, g - 1, b)));
}
int main()
{

    int t = 1;
    while (t--)
    { 
        // Taking input
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> A(a), B(b), C(c);
        for (int i = 0; i < a; i++)  cin >> A[i];
        for (int i = 0; i < b; i++)  cin >> B[i];
        for (int i = 0; i < c; i++)  cin >> C[i];
        // Sorting is done because for max Area,we should choose longer sticks first.
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        sort(C.begin(), C.end());
        // Initializing dp matrix with -1
        for (int i = 0; i <= a; i++)
        {
            for (int j = 0; j <= b; j++)
            {
                for (int k = 0; k <= c; k++)
                {
                    dp[i][j][k] = -1;
                }
            }
        }
        cout << maxArea(A, B, C, a, b, c); 
    }
    return 0;
}
