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
#include <bitset>
#include <math.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

int N;
long long curr, nums [110], mini [110][110], maxi [110][110];
string s;
char opers [110];

void recurseIt(int li, int ri){
    if(mini[li][ri] != -1 && maxi[li][ri] != -1) return;
    if(li == ri){
        mini[li][ri] = maxi[li][ri] = nums[li];
        return;
    }
    mini[li][ri] = (1ll<<62)-1ll+(1ll<<62); maxi[li][ri] = 0ll;
    for(int i = li; i < ri; i++){
        recurseIt(li, i); recurseIt(i+1, ri);
        if(opers[i] == '+'){
            mini[li][ri] = min(mini[li][ri], mini[li][i]+mini[i+1][ri]);
            maxi[li][ri] = max(maxi[li][ri], maxi[li][i]+maxi[i+1][ri]);
        }
        else{
            mini[li][ri] = min(mini[li][ri], mini[li][i]*mini[i+1][ri]);
            maxi[li][ri] = max(maxi[li][ri], maxi[li][i]*maxi[i+1][ri]);
        }
    }
}

int main(){
    //freopen("nocow.in", "r", stdin); freopen("nocow.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    while(true){
        cin >> s; s += '+';
        if(s.compare("END+") == 0) break;
        N = 0; curr = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '+' || s[i] == '*'){
                nums[N] = curr; opers[N] = s[i];
                curr = 0; N++;
            }
            else curr = curr*10+(s[i]-'0');
        }
        memset(mini, -1, sizeof(mini)); memset(maxi, -1, sizeof(maxi));
        recurseIt(0, N-1); cout << mini[0][N-1] << ' ' << maxi[0][N-1] << '\n';
    }
    return 0;
}
