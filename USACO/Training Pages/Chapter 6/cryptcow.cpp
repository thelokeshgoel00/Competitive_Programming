/*
ID: vamaddu1
PROG: cryptcow
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
#include <assert.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

int N, numOper, nlen;
string s, ori = "Begin the Escape execution at the Break of Dawn", unraveled;
unordered_set<long long> visited;

bool precheckIt(){
    if((N-47)%3 != 0) return false;
    int freq [2][128]; memset(freq, 0, sizeof(freq));
    for(int i = 0; i < 47; i++) freq[0][ori[i]]++;
    for(int i = 0; i < s.length(); i++) freq[1][s[i]]++;
    for(int i = 0; i < 128; i++){
        if(i == 'C' || i == 'O' || i == 'W') continue;
        if(freq[0][i] != freq[1][i]) return false;
    }
    if(freq[0]['C']-freq[1]['C'] != freq[0]['O']-freq[1]['O']) return false;
    if(freq[0]['C']-freq[1]['C'] != freq[0]['W']-freq[1]['W']) return false;
    return true;
}

bool beforeC(){
    for(int i = 0; i < nlen; i++){
        if(unraveled[i] == 'C') break;
        if(unraveled[i] != ori[i]) return false;
    }
    return true;
}

bool afterW(){
    for(int i = nlen-1, j = 46; i > -1; i--, j--){
        if(unraveled[i] == 'W') break;
        if(unraveled[i] != ori[j]) return false;
    }
    return true;
}

bool helpIt(string curr, int st, int en){
    for(int i = 0; i+en-st <= 47; i++){
        bool possible = true;
        for(int j = 0; j < en-st; j++)
            if(unraveled[st+j] != ori[i+j]){
                possible = false;
                break;
            }
        if(possible) return true;
    }
    return false;
}

bool checkBetween(){
    int st = 0;
    for(int i = 0; i < nlen; i++){
        if(!(unraveled[i] == 'C' || unraveled[i] == 'O' || unraveled[i] == 'W')) continue;
        if(!helpIt(unraveled, st, i)) return false;
        st = i+1;
    }
    return helpIt(unraveled, st, nlen);
}

long long hashIt(){
    long long hashy = 0;
    for(int i = 0; i < nlen; i++) hashy = hashy*149ll+unraveled[i];
    return hashy;
}

string makeString(string curr, int i, int j, int k){
    string ss = "";
    for(int a = 0; a < i; a++) ss += curr[a];
    for(int a = 0; a < k-j-1; a++) ss += curr[a+j+1];
    for(int a = 0; a < j-i-1; a++) ss += curr[a+i+1];
    for(int a = 0; a < curr.length()-k-1; a++) ss += curr[a+k+1];
    return ss;
}

bool recurseIt(string curr, int operations){
    if(operations == 0) return curr.compare(ori) == 0;
    for(int j = 0; j < N-(numOper-operations)*3; j++){
        if(curr[j] != 'O') continue;
        for(int i = 0; i < j; i++){
            if(curr[i] != 'C') continue;
            for(int k = j+1; k < N-(numOper-operations)*3; k++){
                if(curr[k] != 'W') continue;
                unraveled = makeString(curr, i, j, k); nlen = N-(numOper-operations+1)*3;
                if(!beforeC() || !afterW() || !checkBetween()) continue;
                long long val = hashIt();
                if(visited.find(val) != visited.end()) continue;
                if(recurseIt(unraveled, operations-1)) return true;
                visited.insert(val);
            }
        }
    }
    return false;
}

int main(){
    freopen("cryptcow.in", "r", stdin); freopen("cryptcow.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    getline(cin, s); N = s.length(); numOper = (N-47)/3;
    if(!precheckIt() || !recurseIt(s, numOper)) cout << "0 0\n";
    else cout << "1 " << numOper << '\n';
    return 0;
}
