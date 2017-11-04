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

int K, visited [100010];
deque<int> dq;

int main(){
    //freopen("fortmoo.in", "r", stdin); freopen("fortmoo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> K; fill(visited, visited+K, 1000000);
    visited[1] = 1; dq.push_back(1);
    while(dq.size() > 0){
        int now = dq.front(); dq.pop_front();
        if(visited[(now*10)%K] > visited[now]){
            visited[(now*10)%K] = visited[now];
            dq.push_front((now*10)%K);
        }
        if(visited[(now+1)%K] > visited[now]+1){
            visited[(now+1)%K] = visited[now]+1;
            dq.push_back((now+1)%K);
        }
    }
    cout << visited[0] << '\n';
    return 0;
}
