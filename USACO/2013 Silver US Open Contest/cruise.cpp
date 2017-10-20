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

int N, M;
long long K;
pair<int, int> adjacency [1010], s1 = make_pair(1, 0), s2 = make_pair(1, 0);
string s;

pair<int, int> getNext(pair<int, int> now){
    if(s[now.second] == 'L') return make_pair(adjacency[now.first].first, (now.second+1)%M);
    else return make_pair(adjacency[now.first].second, (now.second+1)%M);
}

int main(){
    freopen("cruise.in", "r", stdin); freopen("cruise.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M >> K; K *= M;
    for(int i = 1; i <= N; i++) cin >> adjacency[i].first >> adjacency[i].second;
    for(int i = 0; i < M; i++){
        char c; cin >> c;
        s += c;
    }
    while(K > 0){
        s1 = getNext(s1); s2 = getNext(getNext(s2));
        K--;
        if(s1.first == s2.first && s1.second == s2.second) break;
    }
    if(K > 0){
        int cycleLen = 1;
        for(s1 = getNext(s1); s1.first != s2.first || s1.second != s2.second; cycleLen++) s1 = getNext(s1);
        K %= cycleLen;
        while(K > 0){ s1 = getNext(s1); K--; }
    }
    cout << s1.first << '\n';
    return 0;
}
