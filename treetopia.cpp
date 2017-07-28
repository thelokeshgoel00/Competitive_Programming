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

int numPlaces, bestRemoteness = 100010, height [100001], pathLength = 0;
long long counter = 0;
vector<int> centers, adjacency [100001];

void dfsOne(int curr, int parent){ //Roots the tree and finds heights of each node
    for(int i = 0; i < adjacency[curr].size(); i++){
        int next = adjacency[curr][i];
        if(next == parent) continue;
        dfsOne(next, curr);
        height[curr] = max(height[curr], height[next]+1);
    }
}

void dfsTwo(int curr, int parent, int curPathLength){ //Finds the center(s)
    int best1 = 0, best2 = 0;
    for(int i = 0; i < adjacency[curr].size(); i++){
        int next = adjacency[curr][i];
        if(next == parent) continue;
        if(height[next]+1 > best1){
            best2 = best1;
            best1 = height[next]+1;
        }
        else if(height[next]+1 > best2) best2 = height[next]+1;
    }
    for(int i = 0; i < adjacency[curr].size(); i++){
        int next = adjacency[curr][i];
        if(next == parent) continue;
        int nextPathLength = height[next]+1 == best1 ? best2 : best1;
        nextPathLength = 1+max(nextPathLength, curPathLength);
        dfsTwo(next, curr, nextPathLength);
    }
    int remoteness = max(curPathLength, height[curr]);
    if(remoteness < bestRemoteness){ centers.clear(); bestRemoteness = remoteness; }
    if(remoteness == bestRemoteness) centers.push_back(curr);
}

long long countIt(int curr, int parent, int heightLeft){
    if(heightLeft == 0) return 1;
    long long sum = 0;
    for(int i = 0; i < adjacency[curr].size(); i++){
        int next = adjacency[curr][i];
        if(next == parent) continue;
        sum += countIt(next, curr, heightLeft-1);
     }
     return sum;
}

int main(){
    cin >> numPlaces; memset(height, 0, sizeof(height));
    for(int i = 0; i < numPlaces-1; i++){
        int a, b; cin >> a >> b;
        adjacency[a].push_back(b); adjacency[b].push_back(a);
    }
    dfsOne(1, 0);
    dfsTwo(1, 0, 0);
    if(centers.size() == 1){
        pathLength = 2*bestRemoteness;
        long long runningSum = 0;
        for(int i = 0; i < adjacency[centers[0]].size(); i++){
            long long add = countIt(adjacency[centers[0]][i], centers[0], bestRemoteness-1);
            counter += add*runningSum;
            runningSum += add;
        }
    }
    else{
        pathLength = 2*bestRemoteness-1;
        counter = countIt(centers[0], centers[1], bestRemoteness-1)*countIt(centers[1], centers[0], bestRemoteness-1);
    }
    cout << pathLength << " " << counter << '\n';
    return 0;
}
