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
#define INF 1000000000000000000
#define MOD 1000000007

int N, M, lo = 0, hi = 0, dupes, ret;
string spotty [510], plain [510];
long long spottyHashes [510], plainHashes [510], powMod [510];

int main(){
    freopen("cownomics.in", "r", stdin); freopen("cownomics.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    powMod[0] = 1ll; for(int i = 1; i < 510; i++) powMod[i] = (powMod[i-1]*149ll)%MOD;
    cin >> N >> M; ret = M; dupes = N;
    for(int i = 0; i < N; i++) cin >> spotty[i];
    for(int i = 0; i < N; i++) cin >> plain[i];
    fill(spottyHashes, spottyHashes+510, 0ll); fill(plainHashes, plainHashes+510, 0ll);
    while(hi < M){
        set<long long> hashes;
        if(dupes == 0){
            ret = min(ret, hi-lo);
            for(int i = 0; i < N; i++)
                hashes.insert(spottyHashes[i] = (spottyHashes[i]-(powMod[hi-lo-1]*(long long)spotty[i][lo])%MOD+MOD)%MOD);
            for(int i = 0; i < N; i++)
                if(hashes.find(plainHashes[i] = (plainHashes[i]-(powMod[hi-lo-1]*(long long)plain[i][lo])%MOD+MOD)%MOD) != hashes.end())
                    dupes++;
            lo++;
        }
        else{
            dupes = 0;
            for(int i = 0; i < N; i++)
                hashes.insert(spottyHashes[i] = (spottyHashes[i]*149ll+(long long)spotty[i][hi])%MOD);
            for(int i = 0; i < N; i++)
                if(hashes.find(plainHashes[i] = (plainHashes[i]*149ll+(long long)plain[i][hi])%MOD) != hashes.end())
                    dupes++;
            hi++;
        }
    }
    cout << ret << '\n';
    return 0;
}
