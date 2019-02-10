/*
ID: vamaddu1
LANG: C++11
TASK: robots
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
#include <bitset>
#include <math.h>
#include <assert.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
template <class T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

#define PI atan2(0, -1)
#define epsilon 1e-9
#define INF 5000000000000000000
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

struct State{
    pair<int, int> locone, loctwo;
    int tiempo;
    State(pair<int, int> a, pair<int, int> b, int c){
        locone = a; loctwo = b;
        tiempo = c;
    }
    State(){ locone = loctwo = mp(0, 0); tiempo = 0; }
};

int paramone [3], paramtwo [3], dp [21][21][21][21][12], dx [] = {-1, 0, 1, 0}, dy [] = {0, 1, 0, -1}, ret = MOD;
char gridone [25][25], gridtwo [25][25];
vector<pair<pair<int, int>, pair<int, int>>> guardsone, guardstwo;
pair<int, int> stone, sttwo;
queue<State> qq;

void bombIt(){
    for(int a = 0; a < 21; a++)
        for(int b = 0; b < 21; b++)
            for(int c = 0; c < 21; c++)
                for(int d = 0; d < 21; d++)
                    for(int e = 0; e < 12; e++)
                        dp[a][b][c][d][e] = -1;
}

bool inBoundsOne(pair<int, int> locone){
    if(!(locone.f > -1 && locone.s > -1)) return false;
    if(!(locone.f < paramone[0] && locone.s < paramone[1])) return false;
    return gridone[locone.f][locone.s] == '.';
}

bool inBoundsTwo(pair<int, int> loctwo){
    if(!(loctwo.f > -1 && loctwo.s > -1)) return false;
    if(!(loctwo.f < paramtwo[0] && loctwo.s < paramtwo[1])) return false;
    return gridtwo[loctwo.f][loctwo.s] == '.';
}

bool escapeOne(pair<int, int> locone){
    if(!(locone.f > -1 && locone.s > -1)) return true;
    if(!(locone.f < paramone[0] && locone.s < paramone[1])) return true;
    return false;
}

bool escapeTwo(pair<int, int> loctwo){
    if(!(loctwo.f > -1 && loctwo.s > -1)) return true;
    if(!(loctwo.f < paramtwo[0] && loctwo.s < paramtwo[1])) return true;
    return false;
}

pair<pair<int, int>, pair<int, int>> getPositions(pair<pair<int, int>, pair<int, int>> guard, int tiempo){
    pair<int, int> curr = guard.f; int step = 0; pair<pair<int, int>, pair<int, int>> lol;
    for(int i = 1; i < guard.s.f; i++){
        if(step == (tiempo+1)%(2*guard.s.f-2)) lol.s = curr;
        else if(step == tiempo%(2*guard.s.f-2)) lol.f = curr;
        curr.f += dx[guard.s.s]; curr.s += dy[guard.s.s];
        step++;
    }
    for(int i = 1; i < guard.s.f; i++){
        if(step == (tiempo+1)%(2*guard.s.f-2)) lol.s = curr;
        else if(step == tiempo%(2*guard.s.f-2)) lol.f = curr;
        curr.f += dx[(guard.s.s+2)%4]; curr.s += dy[(guard.s.s+2)%4];
        step++;
    }
    return lol;
}

int main(){
    freopen("robots.in", "r", stdin); freopen("robots.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> paramone[0] >> paramone[1];
    for(int i = 0; i < paramone[0]; i++)
        for(int j = 0; j < paramone[1]; j++){
            cin >> gridone[i][j];
            if(gridone[i][j] == 'X'){
                gridone[i][j] = '.';
                stone = mp(i, j);
            }
        }
    cin >> paramone[2];
    for(int i = 0; i < paramone[2]; i++){
        int R, C, L; char D; cin >> R >> C >> L >> D; R--; C--;
        if(D == 'N') guardsone.pb(mp(mp(R, C), mp(L, 0)));
        if(D == 'E') guardsone.pb(mp(mp(R, C), mp(L, 1)));
        if(D == 'S') guardsone.pb(mp(mp(R, C), mp(L, 2)));
        if(D == 'W') guardsone.pb(mp(mp(R, C), mp(L, 3)));
    }
    cin >> paramtwo[0] >> paramtwo[1];
    for(int i = 0; i < paramtwo[0]; i++)
        for(int j = 0; j < paramtwo[1]; j++){
            cin >> gridtwo[i][j];
            if(gridtwo[i][j] == 'X'){
                gridtwo[i][j] = '.';
                sttwo = mp(i, j);
            }
        }
    cin >> paramtwo[2];
    for(int i = 0; i < paramtwo[2]; i++){
        int R, C, L; char D; cin >> R >> C >> L >> D; R--; C--;
        if(D == 'N') guardstwo.pb(mp(mp(R, C), mp(L, 0)));
        if(D == 'E') guardstwo.pb(mp(mp(R, C), mp(L, 1)));
        if(D == 'S') guardstwo.pb(mp(mp(R, C), mp(L, 2)));
        if(D == 'W') guardstwo.pb(mp(mp(R, C), mp(L, 3)));
    }
    bombIt(); dp[stone.f][stone.s][sttwo.f][sttwo.s][0] = 0;
    qq.push(State(stone, sttwo, 0));
    while(qq.size() > 0){
        State now = qq.front(); qq.pop();
        for(int q = 0; q < 4; q++){
            pair<int, int> newone = mp(now.locone.f+dx[q], now.locone.s+dy[q]);
            if(now.locone == mp(20, 20)) newone = mp(20, 20);
            else if(!inBoundsOne(newone)){
                if(escapeOne(newone)) newone = mp(20, 20);
                else newone = now.locone;
            }
            bool okone = true;
            for(pair<pair<int, int>, pair<int, int>> guard : guardsone){
                pair<pair<int, int>, pair<int, int>> loc = getPositions(guard, now.tiempo);
                if(newone == loc.s) okone = false;
                if(newone == loc.f && now.locone == loc.s) okone = false;
                if(!okone) break;
            }
            if(!okone) continue;
            pair<int, int> newtwo = mp(now.loctwo.f+dx[q], now.loctwo.s+dy[q]);
            if(now.loctwo == mp(20, 20)) newtwo = mp(20, 20);
            else if(!inBoundsTwo(newtwo)){
                if(escapeTwo(newtwo)) newtwo = mp(20, 20);
                else newtwo = now.loctwo;
            }
            bool oktwo = true;
            for(pair<pair<int, int>, pair<int, int>> guard : guardstwo){
                pair<pair<int, int>, pair<int, int>> loc = getPositions(guard, now.tiempo);
                if(newtwo == loc.s) oktwo = false;
                if(newtwo == loc.f && now.loctwo == loc.s) oktwo = false;
                if(!oktwo) break;
            }
            if(!oktwo) continue;
            if(dp[newone.f][newone.s][newtwo.f][newtwo.s][(now.tiempo+1)%12] == -1){
                int val = dp[now.locone.f][now.locone.s][now.loctwo.f][now.loctwo.s][now.tiempo]+1;
                dp[newone.f][newone.s][newtwo.f][newtwo.s][(now.tiempo+1)%12] = val;
                qq.push(State(newone, newtwo, (now.tiempo+1)%12));
                if(newone == mp(20, 20) && newtwo == mp(20, 20))
                    ret = min(ret, dp[20][20][20][20][(now.tiempo+1)%12]);
            }
        }
    }
    if(ret == MOD) ret = -1;
    cout << ret << '\n';
    return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
