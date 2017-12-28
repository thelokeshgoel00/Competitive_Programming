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

int N;
string ori, banned [100010], ret = "";
map<int, unordered_map<long long, string>> hashTable; // length, hash, string
long long hashPow [100010];
vector<long long> curHashes;

int main(){
    freopen("censor.in", "r", stdin); freopen("censor.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> ori >> N; curHashes.push_back(0); hashPow[0] = 1;
    for(int i = 0; i < N; i++){
        cin >> banned[i];
        long long curHash = 0;
        for(int j = 0; j < banned[i].length(); j++) curHash = (curHash*101+(banned[i][j]-'a'))%MOD;
        hashTable[banned[i].length()][curHash] = banned[i];
    }
    for(int i = 0; i < ori.length(); i++){
        curHashes.push_back((curHashes.back()*101+(ori[i]-'a'))%MOD);
        hashPow[i+1] = (hashPow[i]*101)%MOD; ret += ori[i];
        for(auto it = hashTable.begin(); it != hashTable.end(); it++){
            int len = it->first;
            if(len > ret.length()) break;
            long long subHash = (curHashes.back()-(curHashes[ret.length()-len]*hashPow[len])%MOD+MOD)%MOD;
            auto IT = it->second.find(subHash);
            if(IT != it->second.end()){
                ret = ret.substr(0, ret.length()-len);
                curHashes.resize(curHashes.size()-len);
                break;
            }
        }
    }
    cout << ret << '\n';
    return 0;
}
