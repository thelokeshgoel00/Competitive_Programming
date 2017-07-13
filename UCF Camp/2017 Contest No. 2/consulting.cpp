#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string.h>

using namespace std;

int employees, ret = 10000000, needed [20], drain [20], parent [20];
vector<int> children [20];
int dp [20][1<<20];

int solve(int last, int mask){
    if(dp[last][mask] != -1) return dp[last][mask];
    if(mask == (1<<employees)-1) return dp[last][mask] = needed[last];
    dp[last][mask] = 10000000;
    for(int i = 0; i < employees; i++){
        if((mask&(1<<i)) > 0 || (mask&(1<<parent[i])) == 0) continue;
        dp[last][mask] = min(dp[last][mask], max(needed[last], drain[last]+solve(i, mask|(1<<i))));
    }
    return dp[last][mask];
}

int main(){
    cin >> employees;
    for(int i = 0; i < employees; i++){
        int a, b, c; cin >> a >> b >> c;
        if(a != -1) children[a].push_back(i);
        parent[i] = a; needed[i] = b; drain[i] = c;
    }
    memset(dp, -1, sizeof(dp)); 
    cout << solve(0, 1) << endl;
    return 0;
}
