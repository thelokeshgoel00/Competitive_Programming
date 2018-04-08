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

int N;
long long M;
vector<vector<long long>> transition, ret;

void generateIt(int idx, int li, int ri){
    if(idx == N){
        transition[li][ri]++;
        return;
    }
    generateIt(idx+1, li, ri);
    generateIt(idx+1, li|(1<<idx), ri);
    generateIt(idx+1, li, ri|(1<<idx));
    if(idx < N-1) generateIt(idx+2, li, ri);
}

vector<vector<long long>> matrixMult(vector<vector<long long>> a, vector<vector<long long>> b){
    vector<vector<long long>> c(a.size(), vector<long long>(b[0].size()));
    for(int i = 0; i < c.size(); i++)
        for(int j = 0; j < c[0].size(); j++)
            for(int k = 0; k < a[0].size(); k++){
                c[i][j] += (a[i][k]*b[k][j])%(MOD-7);
                c[i][j] %= (MOD-7);
            }
    return c;
}

vector<vector<long long>> matrixExpo(vector<vector<long long>> mat, long long x){
    if(x == 1) return mat;
    vector<vector<long long>> half = matrixExpo(mat, x/2);
    vector<vector<long long>> ans = matrixMult(half, half);
    if(x%2 == 1) return matrixMult(mat, ans);
    else return ans;

}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M; transition.assign(1<<N, vector<long long>(1<<N));
    generateIt(0, 0, 0); ret = matrixExpo(transition, M);
    cout << ret[0][0] << '\n';
    return 0;
}
