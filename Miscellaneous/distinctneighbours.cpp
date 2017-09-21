#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string.h>
#include <math.h>

using namespace std;

#define PI 3.141592653589793
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, numElements;
long long freq [1010], combo [1010][1010], dp [2][1010];
vector<int> numbers;

int main(){
    //freopen("subrev.in", "r", stdin); freopen("subrev.out", "w", stdout);
    scanf("%d", &N); memset(freq, 0, sizeof(freq));
    memset(combo, 0ll, sizeof(combo)); memset(dp, 0ll, sizeof(dp));
    combo[0][0] = 1;
    for(int i = 1; i < 1010; i++){
        combo[i][0] = 1;
        for(int j = 1; j <= i; j++) combo[i][j] = (combo[i-1][j]+combo[i-1][j-1])%MOD;
    }
    for(int i = 0; i < N; i++){
        int x; scanf("%d", &x);
        freq[x]++;
    }
    for(int i = 0; i < 1010; i++)
        if(freq[i] != 0)
            numbers.push_back(freq[i]);
    dp[0][numbers[0]-1] = 1ll; numElements = numbers[0];
    for(int i = 1; i < numbers.size(); i++){
        int number = numbers[i]; memset(dp[i%2], 0ll, sizeof(dp[i%2]));
        for(int badAdjacent = 0; badAdjacent < numElements; badAdjacent++){
            if(dp[(i-1)%2][badAdjacent] == 0) continue;
            for(int numSplits = 1; numSplits <= min(number, numElements+1); numSplits++)
                for(int chosenBad = 0; chosenBad <= min(numSplits, badAdjacent); chosenBad++){
                    int goodAdjacent = numElements+1-badAdjacent;
                    int chosenGood = numSplits-chosenBad;
                    if(chosenGood < 0 || chosenGood > goodAdjacent) continue;
                    int newBadAdjacent = badAdjacent-chosenBad+number-numSplits;
                    long long numWays = combo[number-1][numSplits-1]*combo[goodAdjacent][chosenGood]%MOD*combo[badAdjacent][chosenBad]%MOD;
                    numWays = (numWays*dp[(i-1)%2][badAdjacent])%MOD;
                    dp[i%2][newBadAdjacent] = (dp[i%2][newBadAdjacent]+numWays)%MOD;
                }
        }
        numElements += number;
    }
    cout << dp[(numbers.size()-1)%2][0] << '\n';
    return 0;
}
