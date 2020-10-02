
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define w(t) int t; cin>>t; while(t--)
#define fo(i,n) for(int i=0;i<n;i++)
#define endl "\n" 
#define MOD 1000000007

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
        // Handling Edge Cases
    if (v[0] == *max_element(v.begin(), v.end()))
    {
        cout << v[0];
        return 0;
    }
    if (k >= n - 1)  // as if k>=n-1,then ans will be max_element.
    {
        cout << *max_element(v.begin(), v.end());
        return 0;
    }
    ll ws = k;
    //  Simple Implementation
    while (true)
    {
        if (v[0] > v[1])
        {
            int x = v[1];
            v.erase(v.begin() + 1);
            v.push_back(x);
            ws--;
            if (ws == 0)
            {
                cout << v[0];
                return 0;
            }
        }
        else
        {
            int x = v[0];
            v.erase(v.begin());
            v.push_back(x);
            ws = k - 1;
        }
    }
    return 0;
}