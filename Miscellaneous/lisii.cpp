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

using namespace std;

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

int N, pos, ret = 0;
pair<int, int> xd;
set<pair<int, int>> table [100010];
set<pair<int, int>>::iterator it, other;

bool comp(set<pair<int, int>> &s, pair<int, int> &p){
    for(it = s.begin(); it != s.end(); it++){
        if(it->f < p.f && it->s < p.s) return true;
        if(it->f >= p.f) return false;
    }
    return false;
}

int findPos(pair<int, int> p){
    int lo = 0, hi = N-1;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(comp(table[mid], p)) lo = mid+1;
        else hi = mid-1;
    }
    return lo;
}

int main(){
	//freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> xd.f >> xd.s; pos = findPos(xd);
        if(pos == N) continue;
        table[pos].insert(xd);
        it = table[pos].find(xd); it++;
        while(it != table[pos].end()){
            if(it->f > xd.f && it->s > xd.s) {
                other = ++it; --it;
                table[pos].erase(it);
                it = other;
            }
            else it++;
        }
        ret = max(ret, pos+1);
    }
    cout << ret << '\n';
    return 0;
}
