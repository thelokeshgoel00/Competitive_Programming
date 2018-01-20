/*
ID: vamaddu1
PROG: cowxor
LANG: C++11
*/

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

int N, cumSum [100010], add, ret = 0, st = 1, en = 1;

struct Node{
    Node* child [2];
    int id;
    Node(){
        child[0] = child[1] = NULL;
        id = -1;
    }
    void placeIt(int x, int index, int num){
        if(index == -1){ id = max(id, num); return; }
        int bitty = (x&(1<<index)) > 0;
        if(child[bitty] == NULL) child[bitty] = new Node();
        child[bitty]->placeIt(x, index-1, num);
    }
    pair<int, int> query(int x, int index){
        if(index == -1) return make_pair(x^cumSum[id], id);
        int bitty = (x&(1<<index)) > 0;
        if(child[1-bitty] != NULL) return child[1-bitty]->query(x, index-1);
        else return child[bitty]->query(x, index-1);
    }
};

Node root;

int main(){
    freopen("cowxor.in", "r", stdin); freopen("cowxor.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; cumSum[0] = 0; root.placeIt(cumSum[0], 20, 0);
    for(int i = 1; i <= N; i++){
        cin >> add; cumSum[i] = cumSum[i-1]^add;
        pair<int, int> tester = root.query(cumSum[i], 20);
        if(tester.first > ret){
            ret = tester.first;
            st = tester.second+1; en = i;
        }
        root.placeIt(cumSum[i], 20, i);
    }
    cout << ret << ' ' << st << ' ' << en << '\n';
    return 0;
}
