#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

struct DJ{
    int parents [40001], heights [40001];
    DJ(){
        for(int i = 0; i < 40001; i++){
            heights[i] = 0;
            parents[i] = i;
        }
    }
    int findParent(int x){
        if(parents[x] == x) return x;
        parents[x] = findParent(parents[x]);
        heights[x] = 1;
        return parents[x];
    }
    bool combine(int x, int y){
        int a = findParent(x); int b = findParent(y);
        if(a == b) return false;
        if(heights[a] > heights[b]) parents[b] = a;
        else if(heights[b] > heights[a]) parents[a] = b;
        else{ parents[b] = a; heights[a]++;}
        return true;
    }
};

struct Edge{
    int a, b, weight;
    Edge(){ a = -1; b = -1; weight = -1; }
    bool operator<(const Edge &other) const{ return other.weight < weight; }
};

int N, M, ret = 0;
vector<Edge> edges;
DJ ds;

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        Edge temp; scanf("%d %d %d", &temp.a, &temp.b, &temp.weight);
        edges.push_back(temp);
    }
    sort(edges.begin(), edges.end());
    for(int i = 0; i < M; i++){
        ds.combine(edges[i].a, edges[i].b+N);
        ds.combine(edges[i].a+N, edges[i].b);
        if(ds.findParent(edges[i].a) == ds.findParent(edges[i].b)){
            ret = edges[i].weight;
            break;
        }
    }
    cout << ret << '\n';
    return 0;
}
