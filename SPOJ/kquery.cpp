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

int N, Q, aidx, qidx, tree [30010], ret [200010];
pair<int, int> arr [30010];
pair<pair<int, int>, pair<int, int>> queries [200010];

void add(int pos, int x){
    while(pos < 30010){
        tree[pos] += x;
        pos += (pos&-pos);
    }
}

int query(int pos){
    int sum = 0;
    while(pos > 0){
        sum += tree[pos];
        pos -= (pos&-pos);
    }
    return sum;
}

int main(){
    //freopen("fencing.in", "r", stdin); freopen("fencing.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 0; i < N; i++){ cin >> arr[i].first; arr[i].second = i+1; }
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> queries[i].second.first >> queries[i].second.second >> queries[i].first.first;
        queries[i].first.second = i;
    }
    sort(arr, arr+N); sort(queries, queries+Q);
    aidx = N-1; qidx = Q-1;
    while(qidx > -1){
        int k = queries[qidx].first.first;
        while(aidx > -1 && arr[aidx].first > k){
            add(arr[aidx].second, 1);
            aidx--;
        }
        while(qidx > -1 && queries[qidx].first.first == k){
            ret[queries[qidx].first.second] = query(queries[qidx].second.second)-query(queries[qidx].second.first-1);
            qidx--;
        }
    }
    for(int i = 0; i < Q; i++) cout << ret[i] << '\n';
    return 0;
}
