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
#include <math.h>

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N;
multiset<long long> heights;
map<long long, vector<long long>> events;
long long prevEnd = 0ll, ret = 0ll;

int main(){
    //freopen("fortmoo.in", "r", stdin); freopen("fortmoo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 0; i < N; i++){
        long long a, b, h; cin >> a >> b >> h;
        events[a].push_back(h);
        events[b].push_back(-h);
    }
    for(auto it = events.begin(); it != events.end(); it++){
        if(heights.size() > 0) ret += (it->first-prevEnd)*(*heights.rbegin());
        prevEnd = it->first;
        for(long long x : it->second){
            if(x > 0) heights.insert(x);
            else heights.erase(heights.find(-x));
        }
    }
    cout << ret << '\n';
    return 0;
}
