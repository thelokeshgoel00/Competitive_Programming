#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string.h>
#include <math.h>

using namespace std;

int N, K, li = 0, ri = 0, activeGroups = 0, ret = 0;
map<int, int> counts;
vector<int> arr;

int main(){
    freopen("lineup.in", "r", stdin); freopen("lineup.out", "w", stdout);
    cin >> N >> K;
    while(ri < N){
        int now; cin >> now; arr.push_back(now);
        if(counts[now] == 0) activeGroups++;
        counts[now]++;
        while(activeGroups > K+1){
            counts[arr[li]]--;
            if(counts[arr[li]] == 0) activeGroups--;
            li++;
        }
        ret = max(ret, counts[now]); ri++;
    }
    cout << ret << '\n';
    return 0;
}
