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

struct Componente{
    int mini [10], maxi [10], numPlayers;
    Componente(){
        for(int i = 0; i < 10; i++) mini[i] = maxi[i] = -1;
        numPlayers = 0;
    }
    Componente(int arr [10]){
        for(int i = 0; i < 10; i++) mini[i] = maxi[i] = arr[i];
        numPlayers = 1;
    }
    bool operator<(const Componente &other) const{ return mini[0] < other.mini[0]; }
    Componente operator+(const Componente &other) const{
        Componente ret;
        for(int i = 0; i < 10; i++){
            ret.mini[i] = min(mini[i], other.mini[i]);
            ret.maxi[i] = max(maxi[i], other.maxi[i]);
        }
        ret.numPlayers = numPlayers+other.numPlayers;
        return ret;
    }
};

int N, K, stuff [10];
set<Componente> comps;

int main(){
    //freopen("fencing.in", "r", stdin); freopen("fencing.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> K; memset(stuff, 0, sizeof(stuff));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++) cin >> stuff[j];
        Componente curr = Componente(stuff);
        while(comps.size() > 0){
            auto it = comps.lower_bound(curr);
            if(it != comps.begin()){
                it--;
                bool c1 = false, c2 = false;
                for(int i = 0; i < K; i++){
                    if((*it).maxi[i] > curr.mini[i]) c1 = true;
                    if((*it).mini[i] < curr.maxi[i]) c2 = true;
                }
                if(c1 && c2){
                    curr = curr+(*it); comps.erase(it);
                    continue;
                }
            }
            it = comps.lower_bound(curr);
            if(it != comps.end()){
                bool c1 = false, c2 = false;
                for(int i = 0; i < K; i++){
                    if((*it).maxi[i] > curr.mini[i]) c1 = true;
                    if((*it).mini[i] < curr.maxi[i]) c2 = true;
                }
                if(c1 && c2){
                    curr = curr+(*it); comps.erase(it);
                    continue;
                }
            }
            break;
        }
        comps.insert(curr);
        cout << (*comps.rbegin()).numPlayers << '\n';
    }
    return 0;
}
