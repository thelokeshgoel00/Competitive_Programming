//I've been expecting you <3
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
// int hammingDistance(int x, int y)
// {
//     int z = x ^ y, cnt = 0;
//     cout<<z;
//     for (int i = 1; i <= 8;i<<1)
//     {
//         if (z & i)
//             cnt++;
//     }
//     return cnt;
// }
int main()
{
    int z=1^4,cnt=0;
    // cout << z;
    // int one=z&3;
    // cout<<" "<<one;
    while(z>0)
    {
        if (z & 1)
            cnt++;
        z=z>>1;
    }
    cout<<cnt;
}