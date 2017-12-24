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

int N, M, cumSum [210][210], ret = 0;
char grid [210][210];

int main(){
    freopen("fortmoo.in", "r", stdin); freopen("fortmoo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N >> M; memset(cumSum, 0, sizeof(cumSum));
    for(int i = 1; i <= N; i++){
        string s; cin >> s;
        for(int j = 1; j <= M; j++){
            grid[i][j] = s[j-1];
            cumSum[i][j] = cumSum[i-1][j]+cumSum[i][j-1]-cumSum[i-1][j-1];
            if(s[j-1] == 'X') cumSum[i][j]++;
        }
    }
    for(int a = 1; a <= M; a++)
        for(int b = a; b <= M; b++){
            int botRow = 0;
            for(int topRow = 1; topRow <= N; topRow++){
                bool isValid = cumSum[topRow][b]-cumSum[topRow][a-1]-cumSum[topRow-1][b]+cumSum[topRow-1][a-1] == 0;
                if(isValid){
                    ret = max(ret, b-a+1);
                    if(botRow > 0) ret = max(ret, (b-a+1)*(topRow-botRow+1));
                    else botRow = topRow;
                }
                if(grid[topRow][a] == 'X' || grid[topRow][b] == 'X') botRow = 0;
            }
        }
    cout << ret << '\n';
    return 0;
}
