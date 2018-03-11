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
#define INF 5000000000000000000
#define MOD 1000000007

int N, boxy [3], dp [110], ret;
pair<pair<int, int>, int> boxes [110];

int main(){
    //freopen("dirtraverse.in", "r", stdin); freopen("dirtraverse.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    while(true){
        cin >> N; if(N == 0) break;
        for(int i = 0; i < N; i++){
            cin >> boxy[0] >> boxy[1] >> boxy[2]; sort(boxy, boxy+3);
            boxes[3*i] = make_pair(make_pair(boxy[0], boxy[1]), boxy[2]);
            boxes[3*i+1] = make_pair(make_pair(boxy[0], boxy[2]), boxy[1]);
            boxes[3*i+2] = make_pair(make_pair(boxy[1], boxy[2]), boxy[0]);
        }
        sort(boxes, boxes+3*N); ret = 0;
        for(int i = 0; i < 3*N; i++){
            dp[i] = boxes[i].second;
            for(int j = 0; j < i; j++)
                if(boxes[j].first.first < boxes[i].first.first && boxes[j].first.second < boxes[i].first.second)
                    dp[i] = max(dp[i], dp[j]+boxes[i].second);
            ret = max(ret, dp[i]);
        }
        cout << ret << '\n';
    }
    return 0;
}
