/*
ID: vamaddu1
LANG: C++11
PROG: charrec
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
#include <math.h>

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, corrections [1210][27][20];
long long judgeData [27][20], testData [1210];
pair<int, string> dp [1250], ret;

int normalTest(int pos, int let){
    int cnt = 0;
	for(int i = 0; i < 20; i++) cnt += corrections[i+pos][let][i];
	return cnt;
}

int missingLineTest(int pos, int ignore, int let) {
	int cnt = 0;
	for(int i = 0; i < 20; i++){
        if(i == ignore) continue;
        if(i < ignore) cnt += corrections[i+pos][let][i];
        else cnt += corrections[i+pos-1][let][i];
	}
	return cnt;
}

int dupeLineTest(int pos, int dupe, int let){
    int cnt = 0;
	for(int i = 0; i < 21; i++){
        if(i == dupe) continue;
        if(i < dupe) cnt += corrections[i+pos][let][i];
        else cnt += corrections[i+pos][let][i-1];
	}
	return cnt;
}

pair<int, string> solveIt(int pos){
    if(dp[pos].first != -1) return dp[pos];
    if(pos == N) return dp[pos] = make_pair(0, "");
    if(pos > N) return make_pair(1000000000, "");
    pair<int, string> best = make_pair(1000000000, "");
    if(pos <= N-19){
		pair<int, string> nexty = solveIt(pos+19);
		int mini = 1000000000; char add = (char)('a'-1);
		for(int i = 0; i < 27; i++)
            for(int j = 0; j < 20; j++){
                int temp = missingLineTest(pos, j, i);
                if(temp < mini){ mini = temp; add = (char)(i+'a'-1); }
            }
		nexty.second += add; nexty.first += mini;
		if(nexty.first < best.first) best = nexty;
    }
    if(pos <= N-20){
        pair<int, string> nexty = solveIt(pos+20);
		int mini = 1000000000; char add = (char)('a'-1);
		for(int i = 0; i < 27; i++){
            int temp = normalTest(pos, i);
            if(temp < mini){ mini = temp; add = (char)(i+'a'-1); }
        }
		nexty.second += add; nexty.first += mini;
		if(nexty.first < best.first) best = nexty;
    }
    if(pos <= N-21){
		pair<int, string> nexty = solveIt(pos+21);
		int mini = 1000000000; char add = (char)('a'-1);
		for(int i = 0; i < 27; i++)
            for(int j = 0; j < 21; j++){
                int temp = dupeLineTest(pos, j, i);
                if(temp < mini){ mini = temp; add = (char)(i+'a'-1); }
            }
		nexty.second += add; nexty.first += mini;
		if(nexty.first < best.first) best = nexty;
    }
    return dp[pos] = best;
}

int main(){
    freopen("font.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; memset(judgeData, 0ll, sizeof(judgeData));
    for(int i = 0; i < 27; i++)
        for(int j = 0; j < 20; j++){
            string s; cin >> s;
            for(int k = 0; k < 20; k++){
                judgeData[i][j] *= 2ll;
                judgeData[i][j] += (long long)(s[k]-'0');
            }
        }
    freopen("charrec.in", "r", stdin); freopen("charrec.out", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; memset(testData, 0ll, sizeof(testData)); fill(dp, dp+1250, make_pair(-1, ""));
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        for(int k = 0; k < 20; k++){
            testData[i] *= 2ll;
            testData[i] += (long long)(s[k]-'0');
        }
    }
    for(int i = 0; i < N; i++)
		for(int j = 0; j < 27; j++)
			for(int k = 0; k < 20; k++)
				corrections[i][j][k] = __builtin_popcountll(testData[i]^judgeData[j][k]);
    ret = solveIt(0);
    for(int i = ret.second.length()-1; i > -1; i--){
		if(ret.second[i] == (char)('a'-1)) cout << " ";
		else cout << ret.second[i];
    }
    cout << '\n';
    return 0;
}
