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

int N, S, lo, hi, ret;
vector<int> adjacency [100010];
bool visited [100010];

pair<int, int> checkIt(int curr, int diameterLimit){
    visited[curr] = true;
    pair<int, int> ans = make_pair(0, 0); //ans.first = # of cuts to make, ans.second = maximum diameter remaining in subtree
    vector<int> childHeights;
    for(int i : adjacency[curr]){
        if(visited[i]) continue;
        pair<int, int> temp = checkIt(i, diameterLimit);
        ans.first += temp.first;
        childHeights.push_back(temp.second);
    }
    if(childHeights.size() == 0) return ans;
    sort(childHeights.begin(), childHeights.end()); reverse(childHeights.begin(), childHeights.end());
    int index = 0;
    while(index < childHeights.size()-1 && childHeights[index]+childHeights[index+1]+2 > diameterLimit) index++;
    if(index < childHeights.size()-1 || (index == childHeights.size()-1 && childHeights[index]+1 <= diameterLimit)){
        ans.first += index;
        ans.second = childHeights[index]+1;
    }
    else{
        ans.first += index+1;
        ans.second = 0;
    }
    return ans;
}

int main(){
    //freopen("dec.in", "r", stdin); freopen("dec.out", "w", stdout);
    scanf("%d %d", &N, &S);
    for(int i = 1; i < N; i++){
        int a, b; scanf("%d %d", &a, &b);
        adjacency[a].push_back(b); adjacency[b].push_back(a);
    }
    lo = 0; hi = N-1; ret = hi;
    while(lo <= hi){
        int mid = (lo+hi)/2; memset(visited, false, sizeof(visited));
        pair<int, int> now = checkIt(1, mid);
        if(now.first <= S){
            ret = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    cout << ret << '\n';
    return 0;
}
