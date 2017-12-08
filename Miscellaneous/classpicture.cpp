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

int N, M;
string names [15], ret;
map<string, int> personToIndex;
map<int, string> indexToPerson;
unordered_set<int> badNext [15];
long long dp [15][1050], best;

int main(){
    //freopen("first.in", "r", stdin); freopen("first.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    while(cin >> N){
        personToIndex.clear(); indexToPerson.clear(); memset(dp, -1, sizeof(dp));
        for(int i = 0; i < N; i++){ cin >> names[i]; badNext[i].clear(); dp[i][1<<i] = i; }
        sort(names, names+N);
        for(int i = 0; i < N; i++){ personToIndex[names[i]] = i; indexToPerson[i] = names[i]; }
        cin >> M;
        for(int i = 0; i < M; i++){
            string a, b; cin >> a >> b;
            badNext[personToIndex[a]].insert(personToIndex[b]);
            badNext[personToIndex[b]].insert(personToIndex[a]);
        }
        for(int mask = 1; mask < (1<<N); mask++)
            for(int i = 0; i < N; i++){
                if(dp[i][mask] == -1) continue;
                for(int j = 0; j < N; j++){
                    if((mask&(1<<j)) > 0 || badNext[i].find(j) != badNext[i].end()) continue;
                    if(dp[j][mask^(1<<j)] == -1) dp[j][mask^(1<<j)] = (long long)11*dp[i][mask]+j;
                    else dp[j][mask^(1<<j)] = min(dp[j][mask^(1<<j)], (long long)11*dp[i][mask]+j);
                }
            }
        best = INF;
        for(int i = 0; i < N; i++)
            if(dp[i][(1<<N)-1] != -1)
                best = min(best, dp[i][(1<<N)-1]);
        if(best == INF){ cout << "You all need therapy.\n"; continue; }
        else{
            ret = "";
            for(int i = 0; i < N; i++){
                if(i != N-1) ret = ' '+indexToPerson[(int)(best%11)]+ret;
                else ret = indexToPerson[(int)(best%11)]+ret;
                best /= 11;
            }
        }
        cout << ret << '\n';
    }
    return 0;
}
