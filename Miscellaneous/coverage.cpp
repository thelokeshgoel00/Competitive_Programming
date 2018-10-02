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

int N, parents [5010], heights [5010], compSizes [5010], ret;
pair<double, double> places [5010];
vector<int> close [5010];

int findParent(int x){
    if(x == parents[x]) return x;
    parents[x] = findParent(parents[x]);
    return parents[x];
}

bool combine(int x, int y){
    int a = findParent(x); int b = findParent(y);
    if(a == b) return false;
    if(heights[b] < heights[a]){
        parents[b] = a;
        compSizes[a] += compSizes[b];
    }
    else if(heights[a] < heights[b]){
        parents[a] = b;
        compSizes[b] += compSizes[a];
    }
    else{
        parents[b] = a; heights[a]++;
        compSizes[a] += compSizes[b];
    }
    return true;
}

int testIt(int i, double x, double y){
    int sum = 1; unordered_set<int> comps;
    comps.insert(findParent(i));
    for(int j : close[i])
        if(sqrt(pow(x-places[j].f, 2)+pow(y-places[j].s, 2)) <= 2+epsilon)
            comps.insert(findParent(j));
    for(int a : comps) sum += compSizes[a];
    return sum;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> places[i].f >> places[i].s;
        parents[i] = i; heights[i] = 0; compSizes[i] = 1;
        for(int j = 0; j < i; j++){
            double d = sqrt(pow(places[i].f-places[j].f, 2)+pow(places[i].s-places[j].s, 2));
            if(d <= 2+epsilon) combine(i, j);
            else if(d <= 4+epsilon) close[i].pb(j);
        }
    }
    ret = *max_element(compSizes, compSizes+N)+1;
    for(int i = 0; i < N; i++)
        for(int j : close[i]){
            int p1 = findParent(i), p2 = findParent(j);
            if(p1 == p2) continue;
            double d = sqrt(pow(places[i].f-places[j].f, 2)+pow(places[i].s-places[j].s, 2));
            double theta = atan2(places[j].s-places[i].s, places[j].f-places[i].f), phi = acos(d/4);
            ret = max(ret, testIt(i, places[i].f+2*cos(theta+phi), places[i].s+2*sin(theta+phi)));
            ret = max(ret, testIt(i, places[i].f+2*cos(theta-phi), places[i].s+2*sin(theta-phi)));
        }
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
