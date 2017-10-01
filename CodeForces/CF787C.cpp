#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
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

#define PI 3.141592653589793
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

struct State{
    int pos, turn, ans;
    State(){ pos = turn = ans = -1; }
    State(int x, int y, int z){ pos = x; turn = y; ans = z; }
};

int N, nums [2], arr [2][7010], degree [7010][2], dp [7010][2]; // win = 1, lose = 0
queue<State> q;
bool visited [7010][2];

int main(){
    scanf("%d", &N); memset(visited, false, sizeof(visited));
    scanf("%d", &nums[0]); for(int i = 0; i < nums[0]; i++) scanf("%d", &arr[0][i]);
    scanf("%d", &nums[1]); for(int i = 0; i < nums[1]; i++) scanf("%d", &arr[1][i]);
    for(int i = 2; i <= N; i++){ degree[i][0] = nums[0]; degree[i][1] = nums[1]; }
    dp[1][0] = dp[1][1] = 0; visited[1][0] = visited[1][1] = true;
    q.push(State(1, 0, 0)); q.push(State(1, 1, 0));
    while(q.size() > 0){
        State now = q.front(); q.pop();
        int pos = now.pos, turn = now.turn, ans = now.ans, prevTurn = 1-now.turn;
        dp[pos][turn] = ans;
        if(ans == 0)
            for(int i = 0; i < nums[prevTurn]; i++){
                int step = arr[prevTurn][i], prevPos = pos-step;
                if(prevPos <= 0) prevPos += N;
                if(!visited[prevPos][prevTurn]){
                    visited[prevPos][prevTurn] = true;
                    q.push(State(prevPos, prevTurn, 1));
                }
            }
        else
            for(int i = 0; i < nums[prevTurn]; i++){
                int step = arr[prevTurn][i], prevPos = pos-step;
                if(prevPos <= 0) prevPos += N;
                degree[prevPos][prevTurn]--;
                if(degree[prevPos][prevTurn] == 0 && !visited[prevPos][prevTurn]){
                    visited[prevPos][prevTurn] = true;
                    q.push(State(prevPos, prevTurn, 0));
                }
            }
    }
    for(int j = 0; j < 2; j++){
        for(int i = 2; i <= N; i++){
            if(!visited[i][j]) printf("Loop");
            else if(dp[i][j] == 1) printf("Win");
            else printf("Lose");
            if(i != N) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
