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

int N, K, tree [1000010];
string arr [1000010], testy, construct;
long long curHash, permCount [1000010], ret = 1;
bool trollHash [10000169];
unordered_map<string, int> stringIndex;
vector<int> seq;

void add(int pos, int x){
    while(pos < 1000010){
        tree[pos] += x;
        pos += (pos&-pos);
    }
}

long long query(int pos){
    int sum = 0;
    while(pos > 0){
        sum += tree[pos];
        pos -= (pos&-pos);
    }
    return sum;
}

int main(){
    //freopen("disrupt.in", "r", stdin); freopen("disrupt.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> K; memset(trollHash, false, sizeof(trollHash));
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr+N); permCount[K] = 1;
    for(int i = K-1; i > -1; i--) permCount[i] = ((long long)(N-i)*permCount[i+1])%MOD;
    for(int i = 0; i < N; i++){
        curHash = 0ll;
        for(int j = 0; j < arr[i].length(); j++)
            curHash = (curHash*149ll+(long long)(arr[i][j]-'a'))%10000169;
        trollHash[curHash] = true; stringIndex[arr[i]] = i+1; add(i+1, 1);
    }
    cin >> testy; curHash = 0ll; construct = "";
    for(int i = 0; i < testy.length(); i++){
        curHash = (curHash*149ll+(long long)(testy[i]-'a'))%10000169;
        construct.push_back(testy[i]);
        if(trollHash[curHash] && stringIndex.find(construct) != stringIndex.end()){
            seq.push_back(stringIndex[construct]);
            curHash = 0ll; construct.clear();
        }
    }
    for(int i = 0; i < K; i++){
        ret = (ret+(query(seq[i]-1)*permCount[i+1])%MOD)%MOD;
        add(seq[i], -1);
    }
    cout << ret << '\n';
    return 0;
}
