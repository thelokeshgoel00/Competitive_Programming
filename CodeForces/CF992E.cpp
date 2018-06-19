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
#include <bitset>
#include <math.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

int N, Q, blockSize = 250, blockID = 0, starts [1010], stops [1010], blockNum [200010];
long long arr [200010], sums [1010], maxi [1010];
vector<pair<long long, int>> buckets [1010];

void buildIt(int x){
    sums[x] = maxi[x] = 0; buckets[x].clear();
    for(int i = starts[x]; i <= stops[x]; i++){
        buckets[x].push_back(make_pair(arr[i]-sums[x], i));
        maxi[x] = max(maxi[x], arr[i]-sums[x]);
        sums[x] += arr[i];
    }
    sort(buckets[x].begin(), buckets[x].end());
}

int helpIt(int b, long long val){
    int p = 0;
    for(int z = 8; z > -1; z--)
        if(p+(1<<z) < buckets[b].size() && buckets[b][p+(1<<z)].first <= val)
            p += (1<<z);
    if(buckets[b][p].first == val) return buckets[b][p].second;
    return -1;
}

int findIt(){
    long long s = 0;
    for(int i = 1; i <= blockID; i++){
        if(maxi[i] >= s){
            int ret = helpIt(i, s);
            if(ret != -1) return ret;
        }
        s += sums[i];
    }
    return -1;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> Q;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    for(int i = 1; i <= N; i += blockSize){
        blockID++; starts[blockID] = i; stops[blockID] = min(i+blockSize-1, N);
        for(int j = starts[blockID]; j <= stops[blockID]; j++) blockNum[j] = blockID;
    }
    for(int i = 1; i <= blockID; i++) buildIt(i);
    for(int i = 0; i < Q; i++){
        int p; long long y; cin >> p >> y;
        arr[p] = y; buildIt(blockNum[p]);
        cout << findIt() << '\n';
    }
    return 0;
}
