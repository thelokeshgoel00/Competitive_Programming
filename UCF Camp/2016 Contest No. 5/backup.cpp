#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string.h>
#include <math.h>

using namespace std;

int n, inDegree [10010], seen = 0;
queue<int> q;
vector<int> adjacency [10010];

int main(){
    cin >> n; memset(inDegree, 0, sizeof(inDegree));
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(x == -1) continue;
        adjacency[x].push_back(i); inDegree[i]++;
    }
    for(int i = 0; i <= n; i++)
        if(inDegree[i] == 0)
            q.push(i);
    while(q.size() > 0){
        int now = q.front(); q.pop(); seen++;
        for(int i : adjacency[now]){
            inDegree[i]--;
            if(inDegree[i] == 0) q.push(i);
        }
    }
    if(seen != n+1) cout << "Kiss the universe goodbye!\n";
    else cout << "Everything looks good!\n";
    return 0;
}
