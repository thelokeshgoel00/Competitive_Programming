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
#include <math.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, M, Q;
pair<long long, long long> tree [2510][2510];
map<pair<pair<int, int>, pair<int, int>>, pair<long long, long long>> mp;

void add(int r, int c, pair<long long, long long> x){
    for(int i = r; i <= N; i += (i&-i))
        for(int j = c; j <= M; j += (j&-j)){
            tree[i][j].first += x.first;
            tree[i][j].second += x.second;
        }
}

pair<long long, long long> query(int r, int c){
    pair<long long, long long> ret = make_pair(0, 0);
    for(int i = r; i > 0; i -= (i&-i))
        for(int j = c; j > 0; j -= (j&-j)){
            ret.first += tree[i][j].first;
            ret.second += tree[i][j].second;
        }
    return ret;
}

int main(){
    //freopen("standingout.in", "r", stdin); freopen("standingout.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18); srand(20010216);
    cin >> N >> M >> Q;
    for(int i = 0; i < 2510; i++)
        for(int j = 0; j < 2510; j++)
            tree[i][j] = make_pair(0, 0);
    for(int i = 0; i < Q; i++){
        int e, a, b, c, d; cin >> e >> a >> b >> c >> d;
        if(e == 1){
            pair<long long, long long> addy = make_pair(rand(), rand()), sub = make_pair(-addy.first, -addy.second);
            mp[make_pair(make_pair(a, b), make_pair(c, d))] = addy;
            add(a, b, addy); add(c+1, d+1, addy);
            add(a, d+1, sub); add(c+1, b, sub);
        }
        else if(e == 2){
            pair<long long, long long> addy = mp[make_pair(make_pair(a, b), make_pair(c, d))], sub = make_pair(-addy.first, -addy.second);
            mp[make_pair(make_pair(a, b), make_pair(c, d))] = make_pair(0, 0);
            add(a, b, sub); add(c+1, d+1, sub);
            add(a, d+1, addy); add(c+1, b, addy);
        }
        else{
            pair<long long, long long> st = query(a, b), en = query(c, d);
            if(st == en) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}
