#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <string.h>

using namespace std;

int n, dp [150][150], ret = 0;
vector<int> arr, use;

int runnerFunc(int i, int j){
    if(dp[i][j] > -1) return dp[i][j];
    if(i == j) return dp[i][j] = use[i]%2;
    return dp[i][j] = max(use[i]%2-runnerFunc(i+1, j), use[j]%2-runnerFunc(i, j-1));
}

int solveWithout(int removal){
    use.clear();
    for(int i = 0; i < n-1; i++) use.push_back(arr[(removal+1+i)%n]);
    memset(dp, -1, sizeof(dp));
    return runnerFunc(0, n-2);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        arr.push_back(temp);
    }
    for(int i = 0; i < n; i++)
        if(solveWithout(i) < arr[i]%2)
            ret++;
    cout << ret << '\n';
    return 0;
}
