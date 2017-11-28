/*
ID: vamaddu1
PROG: hidden
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

int N, i = 0, j = 1;
string s = "";

int main(){
    freopen("hidden.in", "r", stdin); freopen("hidden.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    while(s.length() < N){
        string temp; cin >> temp;
        s += temp;
    }
    s += s;
    while(j <= N){
        int k = 0;
        while(k < N){
            if(s[i+k] != s[j+k]) break;
            k++;
        }
        if(k == N) break;
        if(s[i+k] < s[j+k]) j = j+k+1;
        else i = i+k+1;
        if(i == j) j++;
    }
    cout << i << '\n';
    return 0;
}
