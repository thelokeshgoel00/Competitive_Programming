#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
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
pair<int, int> points [210];
set<pair<int, int>> slopes;

int GCF(int a, int b){
    if(b == 0) return a;
    return GCF(b, a%b);
}

int main(){
    //freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> points[i].first >> points[i].second;
        for(int j = 0; j < i; j++){
            int dy = points[i].second-points[j].second, dx = points[i].first-points[j].first;
            if(dy < 0 || (dy == 0 && dx < 0)){ dy = -dy; dx = -dx; }
            int gcf = GCF(abs(dy), abs(dx));
            dy /= gcf; dx /= gcf;
            slopes.insert(make_pair(dy, dx));
        }
    }
    cout << slopes.size() << '\n';
    return 0;
}
