#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define fo(i, n) for (int i = 0; i < n; i++)
#define endl "\n"
#define MOD 1000000007
const ll inf = 1e18;
void Tez()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll min(ll a, ll b)
{
    if (a < b)
        return a;
    return b;
}

ll ans = 0;
map<int, list<int>> mp;
map<int, bool> vis;

void dfs(int ver, int a[], ll &c)
{
    if (vis[ver])
        return;
    vis[ver] = 1;
    for (auto ngr : mp[ver])
    {
        if (!vis[ngr])
        {
            c = min(c, a[ngr - 1]);
            dfs(ngr, a, c);
        }
    }
}
int main()
{
    Tez();
    int n, m;
    cin >> n >> m;
    int a[n];
    fo(i, n)
    {
        cin >> a[i];
        vis[i + 1] = false;
    }
    fo(i, m)
    {
        int x, y;
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    fo(i, n)
    {
        ll c = inf;
        dfs(i + 1, a, c);
        if (c != inf)
        {
            c = min(c, a[i]);
            ans += c;
        }
        else if (mp[i + 1].size() == 0)
        {
            ans += a[i];
        }
    }
    cout << ans;
    return 0;
}
