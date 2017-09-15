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

#define PI 3.141592653589793
#define epsilon 0.000000001
#define INF 1000000000000
#define MOD 1000000007

int N, id [100010], mx [100010], curID = 1, tree [100010], ret [100010];
pair<int, int> ratings [100010];
vector<int> children [100010];

int dfs(int curr){
    id[curr] = curID++; mx[curr] = id[curr];
    for(int next : children[curr]) mx[curr] = max(mx[curr], dfs(next));
    return mx[curr];
}

void add(int pos, int x){
    while(pos < 100010){
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
    freopen("promote.in", "r", stdin); freopen("promote.out", "w", stdout);
    scanf("%d", &N); memset(tree, 0, sizeof(tree));
    for(int i = 1; i <= N; i++){ scanf("%d", &ratings[i].first); ratings[i].second = i; }
    for(int i = 2, x; i <= N; i++){ scanf("%d", &x); children[x].push_back(i); }
    dfs(1); sort(ratings+1, ratings+N+1);
    for(int i = N; i > 0; i--){
        ret[ratings[i].second] = query(mx[ratings[i].second])-query(id[ratings[i].second]-1);
        add(id[ratings[i].second], 1);
    }
    for(int i = 1; i <= N; i++) printf("%d\n", ret[i]);
    return 0;
}
