#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <deque>
#include <string.h>
#include <sstream>
#include <bitset>
#include <math.h>
#include <assert.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
template <class T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int kase, num, dir = 2, dx [] = {1, 0, -1, -1, 0, 1}, dy [] = {0, 1, 1, 0, -1, -1}, freq [10], ret [10010];
map<pair<int, int>, int> places;
pair<int, int> curr = mp(0, 0);
bool used [10];

pair<int, int> getNext(pair<int, int> a, int d){ return mp(a.f+dx[d], a.s+dy[d]); }

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    fill(freq, freq+10, 0);
    num = 1; places[curr] = num; ret[1] = num; freq[num]++; freq[6] = MOD;
    curr = mp(1, 0);
    for(int p = 2; p < 10010; p++){
        if(places.count(getNext(curr, (dir+1)%6)) == 0) dir = (dir+1)%6;
        curr = getNext(curr, dir);
        fill(used, used+10, false);
        for(int i = 0; i < 6; i++)
            if(places.count(getNext(curr, i)))
                used[places[getNext(curr, i)]] = true;
        num = 6;
        for(int i = 1; i < 6; i++)
            if(!used[i] && freq[i] < freq[num])
                num = i;
        places[curr] = num; ret[p] = num; freq[num]++;
        assert(num != 6);
    }
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        int x; cin >> x;
        cout << ret[x] << '\n';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
