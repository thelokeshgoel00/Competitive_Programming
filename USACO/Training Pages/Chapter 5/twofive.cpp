/*
ID: vamaddu1
PROG: twofive
LANG: C++11
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
#include <math.h>

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

string command;
int maxRow [5], maxCol [5], numIn [5], dp [6][6][6][6][6];
bool used [25];

void reset(int letter, int r, int c){
    memset(dp, -1, sizeof(dp)); dp[5][5][5][5][5] = 1;
    maxRow[r] = letter; maxCol[c] = letter;
    used[letter] = true;
}

int calcIt(int a, int b, int c, int d, int e, int letter){
    if(dp[a][b][c][d][e] != -1) return dp[a][b][c][d][e];
    if(used[letter]) return dp[a][b][c][d][e] = calcIt(a, b, c, d, e, letter+1);
    dp[a][b][c][d][e] = 0;
    if(a < 5 && letter > maxRow[0]) dp[a][b][c][d][e] += calcIt(a+1, b, c, d, e, letter+1);
    if(a > b && letter > maxRow[1] && letter > maxCol[b]) dp[a][b][c][d][e] += calcIt(a, b+1, c, d, e, letter+1);
    if(b > c && letter > maxRow[2] && letter > maxCol[c]) dp[a][b][c][d][e] += calcIt(a, b, c+1, d, e, letter+1);
    if(c > d && letter > maxRow[3] && letter > maxCol[d]) dp[a][b][c][d][e] += calcIt(a, b, c, d+1, e, letter+1);
    if(d > e && letter > maxRow[4] && letter > maxCol[e]) dp[a][b][c][d][e] += calcIt(a, b, c, d, e+1, letter+1);
    return dp[a][b][c][d][e];
}

string findGrid(int idx){
    int curr = 0; string ret = ".........................";
    for(int i = 0; i < 5; i++){ maxRow[i] = maxCol[i] = -1; numIn[i] = 0; }
    memset(used, false, sizeof(used));
    for(int i = 0; i < 25; i++){
        numIn[i/5]++;
        for(int j = max(maxRow[i/5], maxCol[i%5])+1; j < 25; j++){
            if(used[j] || j < maxRow[i/5] || j < maxCol[i%5]) continue;
            reset(j, i/5, i%5); int temp = calcIt(numIn[0], numIn[1], numIn[2], numIn[3], numIn[4], 0);
            if(curr+temp >= idx){ ret[i] = (char)('A'+j); break; }
            curr += temp; used[j] = false;
        }
    }
    return ret;
}

int findIndex(string s){
    int ret = 1;
    for(int i = 0; i < 5; i++){ maxRow[i] = maxCol[i] = -1; numIn[i] = 0; }
    memset(used, false, sizeof(used));
    for(int i = 0; i < 25; i++){
        numIn[i/5]++;
        for(int j = max(maxRow[i/5], maxCol[i%5])+1; j < (int)(s[i]-'A'); j++){
            if(used[j] || j < maxRow[i/5] || j < maxCol[i%5]) continue;
            reset(j, i/5, i%5);
            ret += calcIt(numIn[0], numIn[1], numIn[2], numIn[3], numIn[4], 0);
            used[j] = false;
        }
        used[(int)(s[i]-'A')] = true; maxRow[i/5] = maxCol[i%5] = (int)(s[i]-'A');
    }
    return ret;
}

int main(){
    freopen("twofive.in", "r", stdin); freopen("twofive.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> command;
    if(command[0] == 'N'){
        int x; cin >> x;
        cout << findGrid(x) << '\n';
    }
    else{
        string s; cin >> s;
        cout << findIndex(s) << '\n';
    }
    return 0;
}
