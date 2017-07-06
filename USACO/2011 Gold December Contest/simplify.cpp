#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define MOD 1000000007ll

struct dset{
    int parent [40000], height [40000];
    dset(){ for(int i = 0; i < 40000; i++){ parent[i] = i; height[i] = 0; } }
    int findParent(int x){
        if(parent[x] == x) return x;
        parent[x] = findParent(parent[x]);
        height[x] = 1;
        return parent[x];
    }
    bool join(int x, int y){
        int a = findParent(x); int b = findParent(y);
        if(a == b) return false;
        if(height[a] < height[b]) parent[a] = b;
        else if(height[b] < height[a]) parent[b] = a;
        else{ parent[b] = a; height[a]++; }
        return true;
    }
};

struct Edge{
    int weight;
    pair<int, int> places;
    Edge(int a, pair<int, int> b){ weight = a; places = b; }
    bool operator<(const Edge &other) const{ return weight < other.weight; }
};

int N, M, used = 0;
long long length = 0, ways = 1;
vector<Edge> edges;

int main(){
    freopen("simplify.in", "r", stdin); freopen("simplify.out", "w", stdout);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        edges.push_back(Edge(c, make_pair(a-1, b-1)));
    }
    sort(edges.begin(), edges.end()); dset ds; int i = 0;
    while(i < M){
        int j = i, mergeable = 0, same = 0;
        set<pair<int, int>> temp;
        while(j < M && edges[j].weight == edges[i].weight){
            int A = ds.findParent(edges[j].places.first);
            int B = ds.findParent(edges[j].places.second);
            if(A == B){ j++; continue; }
            if(A > B) swap(A, B);
            temp.insert(make_pair(A, B));
            same++; j++;
        }
        while(i < j){
            bool b = ds.join(edges[i].places.first, edges[i].places.second);
            if(b) mergeable++;
            i++;
        }
        used += mergeable;
        length += mergeable*edges[i-1].weight;
        if(same == 3){
            if(mergeable == 1 || (mergeable == 2 && temp.size() == 3)) ways = (ways*3ll)%MOD;
            if(mergeable == 2 && temp.size() == 2) ways = (ways*2ll)%MOD;
        }
        if(same == 2 && mergeable == 1) ways = (ways*2ll)%MOD;
        if(used == N-1) break;
    }
    cout << length << " " << ways << endl;
    return 0;
}
