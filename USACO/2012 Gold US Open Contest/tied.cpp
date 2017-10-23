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

int N, M, group [10010], ret;
pair<int, int> bessie, poles [15], rope [10010];
vector<int> cutPos;

int cross(pair<int, int> a, pair<int, int> b, pair<int, int> c){
    return (b.first-a.first)*(c.second-b.second)-(b.second-a.second)*(c.first-b.first);
}

int main(){
    freopen("tied.in", "r", stdin); freopen("tied.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M >> bessie.first >> bessie.second; ret = N;
    for(int i = 0; i < N; i++) cin >> poles[i].first >> poles[i].second;
    sort(poles, poles+N);
    for(int i = 0; i < M+1; i++) cin >> rope[i].first >> rope[i].second;
    for(int i = 0; i < M; i++)
        if((rope[i].first > poles[0].first) ^ (rope[i+1].first > poles[0].first)){
            int cnt = 0;
            for(int j = 0; j < N; j++)
                if(cross(rope[i], rope[i+1], poles[j]) > 0)
                    cnt++;
            if(rope[i+1].first > poles[0].first) cnt = N-cnt;
            cutPos.push_back(cnt);
        }
    for(int mask = 1; mask < (1<<N); mask++){
        int id = 0; group[0] = 0;
        for(int i = 0; i < N; i++){
            if((mask&(1<<i)) > 0) id++;
            group[i+1] = id;
        }
        stack<int> st;
        for(int i = 0; i < cutPos.size(); i++){
            int curGroup = group[cutPos[i]];
            if(st.size() > 0 && st.top() == curGroup) st.pop();
            else st.push(curGroup);
        }
        if(st.size() == 0) ret = min(ret, N-__builtin_popcount(mask));
    }
    cout << ret << '\n';
    return 0;
}
