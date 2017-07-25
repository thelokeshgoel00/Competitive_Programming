#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> children [200001];
pair<long long, int> pis [200001];
int tree [200001], id [200001], mx [200001], ret [200001], curr = 1, index = 1;
long long L, depth [200001];

void add(int pos, long long x){
    while(pos < 200001){
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

int dfs(int x){
    id[x] = curr++; mx[x] = id[x];
    for(int i = 0; i < children[x].size(); i++){
        int next = children[x][i];
        mx[x] = max(mx[x], dfs(next));
    }
    return mx[x];
}

int main(){
    freopen("runaway.in", "r", stdin); freopen("runaway.out", "w", stdout);
    scanf("%d %lld", &N, &L); depth[0] = 0ll;
    for(int i = 2; i <= N; i++){
        int x; long long y; scanf("%d %lld", &x, &y);
        children[x].push_back(i); depth[i] = depth[x]+y;
    }
    dfs(1);
    for(int i = 1; i <= N; i++) pis[i] = make_pair(depth[i], i);
    sort(pis+1, pis+N+1);
    for(int i = 1; i <= N; i++){
        long long curDepth = pis[i].first; int now = pis[i].second; int from = id[now]; int to = mx[now];
        while(index <= N && curDepth+L >= depth[pis[index].second]){
            add(id[pis[index].second], 1);
            index++;
        }
        ret[now] = query(to)-query(from-1);
    }
    for(int i = 1; i <= N; i++) cout << ret[i] << '\n';
    return 0;
}
