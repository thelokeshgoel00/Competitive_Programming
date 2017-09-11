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
#define INF 1000000000000
#define MOD 1000000007

int N, pos [20010], maxLen;
bool inSeq [20010];
vector<int> seq, ret;

bool dfs(int curr){
    if(curr == N){ ret = seq; return true; }
    inSeq[curr] = true;
    int c, bc, k, j;
    for(int i = 0; i < seq.size(); i++){
        c = curr+seq[i];
        for(k = c, j = seq.size()+2; j < maxLen+1; k *= 2, j++);
        if(k < N) continue;
        if(c <= N && !inSeq[c] && seq.size()+1 <= pos[c]){
            pos[c]= seq.size()+1;
            seq.push_back(c);
            if(dfs(c)) return true;
            seq.pop_back();
        }
    }
    inSeq[curr] = false;
    return false;
}

int main(){
    //freopen("grassplant.in", "r", stdin); freopen("grassplant.out", "w", stdout);
    fill(pos, pos+20010, 2000000000);
    scanf("%d", &N);
    fill(inSeq, inSeq+20010, false);
    seq.clear(); seq.push_back(1); inSeq[0] = true; ret.clear();
    for(int i = 1; ; i++){
        maxLen = i; dfs(1);
        if(ret.size() > 0) break;
    }
    cout << maxLen << '\n'; //ret contains the elements of the actual "Addition Chain"
    return 0;
}
