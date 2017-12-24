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
#define INF 1000000000000000000
#define MOD 1000000007

int N, D, bView [200010], eView [200010], dists [200010];
set<pair<int, int>> sendToB, sendToE;
queue<int> q;

int main(){
    freopen("piepie.in", "r", stdin); freopen("piepie.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(4);
    cin >> N >> D;
    for(int i = 0; i < 2*N; i++){
        cin >> bView[i] >> eView[i];
        bView[i] *= -1; eView[i] *= -1;
        dists[i] = -1;
    }
    for(int i = 0; i < N; i++){
        if(eView[i] == 0){ q.push(i); dists[i] = 1; }
        else sendToB.insert(make_pair(eView[i], i));
        if(bView[N+i] == 0){ q.push(N+i); dists[N+i] = 1; }
        else sendToE.insert(make_pair(bView[N+i], N+i));
    }
    while(q.size() > 0){
        int curr = q.front(); q.pop();
        if(curr < N){
            while(true){
                auto it = sendToE.lower_bound(make_pair(bView[curr], -1));
                if(it == sendToE.end() || bView[curr]+D < bView[(*it).second]) break;
                dists[(*it).second] = dists[curr]+1; q.push((*it).second);
                sendToE.erase(it);
            }
        }
        else{
            while(true){
                auto it = sendToB.lower_bound(make_pair(eView[curr], -1));
                if(it == sendToB.end() || eView[curr]+D < eView[(*it).second]) break;
                dists[(*it).second] = dists[curr]+1; q.push((*it).second);
                sendToB.erase(it);
            }
        }
    }
    for(int i = 0; i < N; i++) cout << dists[i] << '\n';
    return 0;
}
