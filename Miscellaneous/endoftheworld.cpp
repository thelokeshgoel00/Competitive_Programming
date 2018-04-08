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

string s;

long long solveIt(int remaining, char src, char tar, char aux){
    if(remaining == 0) return 0ll;
    else if(s[remaining-1] == src) return (1ll<<(remaining-1))+solveIt(remaining-1, src, aux, tar);
    else return solveIt(remaining-1, aux, tar, src);
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    while(true){
        cin >> s;
        if(s.compare("X") == 0) break;
        cout << solveIt(s.length(), 'A', 'B', 'C') << '\n';
    }
    return 0;
}
