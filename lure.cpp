#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

vector<long> adj[1000001];

long n, dp[3][1000001];
//0 = obligated to cover
//1 = covered from above
//2 = neutral

long go(long type, long now, long from){
    if(dp[type][now] != -1) return dp[type][now];
    if(adj[now].size() == 1 && from != -1){
        if(type == 1) dp[type][now] = 0;
        else dp[type][now] = 1;
        return dp[type][now];
    }
    //long zeroSum = 0L;
    long oneSum = 0L;
    long twoSum = 0L;
    for(long i = 0; i < adj[now].size(); i++){
        if(adj[now][i] != from){
            //zeroSum += go(0, adj[now][i], now);
            oneSum += go(1, adj[now][i], now);
            twoSum += go(2, adj[now][i], now);
        }
    }
    if(type == 0) dp[type][now] = 1+oneSum;
    else if(type == 1) dp[type][now] = min(twoSum, 1L+oneSum);
    else{
        dp[type][now] = 1L+oneSum;
        for(long i = 0; i < adj[now].size(); i++){
            if(adj[now][i] == from) continue;
            dp[type][now] = min(dp[type][now], twoSum-go(2,adj[now][i],now)+go(0,adj[now][i],now));
        }
    }
    return dp[type][now];
}
int main(){
    cin >> n;
    for(long i = 1; i<n; i++){
        long a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    memset(dp, -1, sizeof(dp));
    cout << go(2,0,-1) << '\n';
}
