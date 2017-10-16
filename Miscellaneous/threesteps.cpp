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
#include <math.h>
 
using namespace std;
 
#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007
 
int N, M, color [100010];
vector<int> adjacency [100010];
queue<int> q;
long long black = 0ll, white = 0ll;
 
int main(){
    //freopen("roboherd.in", "r", stdin); freopen("roboherd.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M; memset(color, -1, sizeof(color));
    color[1] = 0; white++; q.push(1);
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        adjacency[a].push_back(b); adjacency[b].push_back(a);
    }
    while(q.size() > 0){
        int now = q.front(); q.pop();
        for(int i : adjacency[now]){
            if(color[i] == color[now]){
                cout << (long long)N*(long long)(N-1ll)/2ll-(long long)M << '\n';
                return 0;
            }
            if(color[i] == -1){
                q.push(i);
                if(color[now] == 1){ color[i] = 0; white++; }
                else{ color[i] = 1; black++; }
            }
        }
    }
    cout << black*white-(long long)M << '\n';
    return 0;
}
