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

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N;
unordered_map<char, int> charToIndex;
long long charFreq [7][7], curTest [7], ret = 0;

void recurseIt(int curr, long long add){
    if(curr == 7){
        int prod = (curTest[0]+curTest[1]+curTest[2]+curTest[2]+curTest[3]+curTest[1])*
                (curTest[4]+curTest[5]+curTest[1]+curTest[2])*(curTest[6]+curTest[5]+curTest[5]);
        if(prod%7 == 0) ret += add;
        return;
    }
    for(int i = 0; i < 7; i++){
        if(charFreq[curr][i] == 0) continue;
        curTest[curr] = i;
        recurseIt(curr+1, add*charFreq[curr][i]);
    }
}

int main(){
    freopen("bgm.in", "r", stdin); freopen("bgm.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; memset(charFreq, 0, sizeof(charFreq));
    charToIndex['B'] = 0; charToIndex['E'] = 1; charToIndex['S'] = 2; charToIndex['I'] = 3;
    charToIndex['G'] = 4; charToIndex['O'] = 5; charToIndex['M'] = 6;
    for(int i = 0; i < N; i++){
        char c; int x, idx; cin >> c >> x; idx = charToIndex[c];
        charFreq[idx][(x%7+7)%7]++;
    }
    recurseIt(0, 1);
    cout << ret << '\n';
    return 0;
}
