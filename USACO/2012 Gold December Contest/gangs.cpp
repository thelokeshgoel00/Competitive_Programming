#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, sol, kontrol = -1, amount = 0;
bool valid;
vector<int> gangSizes;
priority_queue<pair<int, int>> pq;

int maximizeCows(int control, int curCows, int available){
    pq = priority_queue<pair<int, int>>();
    available -= gangSizes[0];
    for(int i = 1; i < M; i++)
        if(gangSizes[i] > 0)
            pq.push(make_pair(gangSizes[i], i));
    for(int i = 0; i < available; i++){
        pair<int, int> now = pq.top(); pq.pop();
        now.first--;
        if(curCows == 0) control = now.second;
        if(control == now.second) curCows++;
        else curCows--;
        if(now.first != 0) pq.push(now);
    }
    if(control == 0) return curCows + gangSizes[0];
    else return gangSizes[0]-curCows;
}

int main(){
    freopen("gangs.in", "r", stdin); freopen("gangs.out", "w", stdout);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        int x; scanf("%d", &x);
        gangSizes.push_back(x);
    }
    int sol = maximizeCows(-1, 0, N);
    if(sol <= 0){ cout << "NO\n"; return 0;}
    cout << "YES\n" << sol << '\n';
    for(int i = N-1; i > -1; i--)
        for(int j = 0; j < M; j++){
            if(gangSizes[j] == 0) continue;
            gangSizes[j]--; valid = false;
            if(amount == 0){
                if(maximizeCows(j, 1, i) == sol){
                    kontrol = j; amount = 1;
                    valid = true;
                }
            }
            else if(kontrol == j){
                if(maximizeCows(kontrol, amount+1, i) == sol){
                    amount++;
                    valid = true;
                }
            }
            else{
                if(maximizeCows(kontrol, amount-1, i) == sol){
                    amount--;
                    valid = true;
                }
            }
            if(valid){ cout << j+1 << '\n'; break; }
            gangSizes[j]++;
        }
    return 0;
}
