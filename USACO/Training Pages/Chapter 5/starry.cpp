/*
ID: vamaddu1
PROG: starry
LANG: C++11
*/

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

struct Node {
    int id;
    vector<pair<int, int>> points;
    Node(int x){ id = x; }
};

int rows, cols, parents [22500], heights [22500], dx [] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy [] = {-1, 0, 1, -1, 1, -1, 0, 1}, curId = 0;
char skymap [150][150];
vector<Node> graph;
map<int, int> parentToIndex;

bool inBounds(int x, int y){ return x > -1 && y > -1 && x < rows && y < cols; }

int findParent(int x){
    if(x == parents[x]) return x;
    parents[x] = findParent(parents[x]);
    heights[x] = 1;
    return parents[x];
}

bool combine(int x, int y){
    int a = findParent(x); int b = findParent(y);
    if(a == b) return false;
    if(heights[b] < heights[a]) parents[b] = a;
    else if(heights[a] < heights[b]) parents[a] = b;
    else{ parents[b] = a; heights[a]++; }
    return true;
}

bool rotateIt(vector<pair<int, int>> a, vector<pair<int, int>> b, int dimen){
    for(int qq = 0; qq < 4; qq++){
        sort(b.begin(), b.end());
        int cx = a[0].first-b[0].first;
        int cy = a[0].second-b[0].second;
        bool isValid = true;
        for(int i = 1; i < a.size(); i++){
            if(cx != a[i].first-b[i].first || cy != a[i].second-b[i].second){
                isValid = false;
                break;
            }
        }
        if(isValid) return true;
        for(int i = 0; i < b.size(); i++){
            swap(b[i].first, b[i].second);
            b[i].second = dimen-b[i].second;
}
    }
    return false;
}

bool checkIt(vector<pair<int, int>> a, vector<pair<int, int>> b, int dimen){
    if(a.size() != b.size()) return false;
    if(rotateIt(a, b, dimen)) return true;
    for(int i = 0; i < b.size(); i++) b[i].second = dimen-b[i].second;
    return rotateIt(a, b, dimen);
}

int main(){
    freopen("starry.in", "r", stdin); freopen("starry.out", "w", stdout);
    scanf("%d %d", &cols, &rows);
    for(int i = 0; i < rows*cols; i++){ parents[i] = i; heights[i] = 0; }
    for(int i = 0; i < rows; i++) scanf("%s", &skymap[i]);
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++){
            if(skymap[i][j] == '0') continue;
            for(int k = 0; k < 4; k++){
                int nr = i+dx[k]; int nc = j+dy[k];
                if(inBounds(nr, nc) && skymap[nr][nc] == '1') combine(nr*cols+nc, i*cols+j);
            }
        }
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++){
            if(skymap[i][j] == '0') continue;
            int parent = findParent(i*cols+j);
            if(parentToIndex.find(parent) == parentToIndex.end()){
                parentToIndex[parent] = (int)graph.size();
                graph.push_back(Node(parentToIndex[parent]));
            }
            graph[parentToIndex[parent]].points.push_back(make_pair(i, j));
        }
    for(int i = 0; i < graph.size(); i++){
        if(graph[i].id != i) continue;
        graph[i].id = curId;
        sort(graph[i].points.begin(), graph[i].points.end());
        for(int j = i+1; j < graph.size(); j++){
            if(graph[j].id != j) continue;
            if(checkIt(graph[i].points, graph[j].points, max(rows, cols))) graph[j].id = curId;
        }
        curId++;
    }
    for(int i = 0; i < graph.size(); i++)
        for(int j = 0; j < graph[i].points.size(); j++)
            skymap[graph[i].points[j].first][graph[i].points[j].second] = graph[i].id+'a';
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++) cout << skymap[i][j];
        cout << '\n';
    }
    return 0;
}
