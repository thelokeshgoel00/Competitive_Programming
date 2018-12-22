/*
ID: vamaddu1
PROG: clocks
LANG: C++11
*/

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

int ori [10], cnt [10], arr [10];
vector<int> ret;

int add [9][9] = {
	{1,1,0,1,1,0,0,0,0},
	{1,1,1,0,0,0,0,0,0},
	{0,1,1,0,1,1,0,0,0},
	{1,0,0,1,0,0,1,0,0},
	{0,1,0,1,1,1,0,1,0},
	{0,0,1,0,0,1,0,0,1},
	{0,0,0,1,1,0,1,1,0},
	{0,0,0,0,0,0,1,1,1},
	{0,0,0,0,1,1,0,1,1}
};

void recurseIt(int moveNum){
    if(moveNum < 9){
        for(int i = 0; i < 4; i++){
            recurseIt(moveNum+1);
            cnt[moveNum]++;
        }
        cnt[moveNum] = 0;
        return;
    }
    for(int i = 0; i < 9; i++) arr[i] = ori[i];
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++){
            arr[j] += cnt[i]*add[i][j];
            arr[j] %= 4;
        }
    int calibrateSum = 0, moveSum = 0;
    for(int i = 0; i < 9; i++){
        calibrateSum += arr[i];
        moveSum += cnt[i];
    }
    if(calibrateSum > 0 || moveSum > ret.size()) return;
    if(moveSum < ret.size()){
        vector<int> temp;
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < cnt[i]; j++)
                temp.pb(i+1);
        ret = temp;
    }
    else if(moveSum == ret.size()){
        vector<int> temp;
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < cnt[i]; j++)
                temp.pb(i+1);
        ret = min(ret, temp);
    }
}

int main(){
    freopen("clocks.in", "r", stdin); freopen("clocks.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    for(int i = 0; i < 50; i++) ret.pb(100);
    for(int i = 0; i < 9; i++){
        int x; cin >> x;
        ori[i] = (x/3)%4;
    }
    recurseIt(0);
    for(int i = 0; i < ret.size(); i++){
        cout << ret[i];
        if(i == ret.size()-1) cout << '\n';
        else cout << ' ';
    }
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
