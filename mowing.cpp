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

#define PI 3.14159265358979
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

#define MAXN (1<<17)
#define MAXV (1<<30)

struct Node{
    int val;
    Node* c [2];
    Node(){ val = 0; c[0] = c[1] = NULL; }
    void update(int L, int R, int pos, int v){ // add v to the element at pos
        if(L == R){
            val += v;
            return;
        }
        int mid = (L+R)/2;
        if(pos <= mid){
            if(!c[0]) c[0] = new Node();
            c[0]->update(L, mid, pos, v);
        }
        else{
            if(!c[1]) c[1] = new Node();
            c[1]->update(mid+1, R, pos, v);
        }
        val = 0;
        if(c[0]) val += c[0]->val;
        if(c[1]) val += c[1]->val;
    }
    int query(int L, int R, int i, int j){ // query sum of segment from i to j (inclusive)
        if(j < L || i > R) return 0;
        if(i <= L && j >= R) return val;
        int mid = (L+R)/2, sum = 0;
        if(c[0]) sum += c[0]->query(L, mid, i, j);
        if(c[1]) sum += c[1]->query(mid+1, R, i, j);
        return sum;
    }
};

struct SegBit{
    Node seg [MAXN+1];
    void update(int x, int y, int v){ // add v to elements at y for each x
        x++; // 1 indexed
        while(x <= MAXN){
            seg[x].update(0, MAXV-1, y, v);
            x += (x&-x);
        }
    }
    int query(int x, int y1, int y2){ // query vertical dimension from y1 to y2 (inclusive) from 0 <= i < x
        int sum = 0;
        while(x > 0){
            sum += seg[x].query(0, MAXV-1, y1, y2);
            x -= (x&-x);
        }
        return sum;
    }
    int query(int x1, int x2, int y1, int y2){ return query(x2+1, y1, y2)-query(x1, y1, y2); } // query sum of rectangle
};

int N, T, hindex = 0, vindex = 0, ret = 0;
pair<int, int> points [100010];
vector<pair<pair<int, int>, pair<int, int>>> horizontalEvents, verticalQueries;
SegBit sb; // horizontal dimension of time and vertical dimension of x's

int main(){
    freopen("mowing.in", "r", stdin); freopen("mowing.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> T;
    for(int i = 0; i < N; i++) cin >> points[i].first >> points[i].second;
    for(int i = 0; i < N-1; i++){
        pair<int, int> a = points[i], b = points[i+1];
        if(a > b) swap(a, b);
        if(a.second == b.second){
            horizontalEvents.push_back(make_pair(make_pair(a.first+1, a.second), make_pair(1, i)));
            horizontalEvents.push_back(make_pair(b, make_pair(-1, i)));
        }
        else verticalQueries.push_back(make_pair(a, make_pair(b.second, i)));
    }
    sort(horizontalEvents.begin(), horizontalEvents.end());
    sort(verticalQueries.begin(), verticalQueries.end());
    while(vindex < verticalQueries.size()){
        int x = verticalQueries[vindex].first.first;
        while(hindex < horizontalEvents.size() && horizontalEvents[hindex].first.first <= x){
            sb.update(horizontalEvents[hindex].second.second, horizontalEvents[hindex].first.second, horizontalEvents[hindex].second.first);
            hindex++;
        }
        while(vindex < verticalQueries.size() && verticalQueries[vindex].first.first == x){
            int lo = verticalQueries[vindex].first.second;
            int hi = verticalQueries[vindex].second.first;
            int tiempo1 = verticalQueries[vindex].second.second-T+1;
            int tiempo2 = verticalQueries[vindex].second.second+T;
            if(tiempo2 < MAXN-1) ret += sb.query(tiempo2, MAXN-1, lo+1, hi-1);
            if(tiempo1 > -1) ret += sb.query(tiempo1, lo+1, hi-1);
            vindex++;
        }
    }
    cout << ret << '\n';
    return 0;
}
