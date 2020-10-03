#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)
#define fo(i, n) for (int i = 0; i < n; i++)
//    #define endl "\n"
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
    map<int, int> mp;
    int lind = 0, rind = 0;
    while (n--)
    {
        char c;
        int id;
        cin >> c >> id;
        if (c == '?')
        {
            int answer = min(abs(lind - mp[id] + 1), abs(rind - mp[id] - 1));
            cout << answer << endl; //Printing the answer
        }
        else
        {
            if (c == 'L')
            {
                mp[id] = lind;
                if (lind == 0)
                    rind++;
                lind--;
            }
            else
            {
                mp[id] = rind;
                if (rind == 0)
                    lind--;
                rind++;
            }
        }
    }
    return 0;
}