#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <unordered_set>

using namespace std;

int N, M, Q, perm[31][100001] ;

int main(){
    freopen("shufflegold.in", "r", stdin); freopen("shufflegold.out", "w", stdout);
    scanf("%d %d %d", &N, &M, &Q);
    for(int i = 1; i <= M; i++){
        int x; scanf("%d",&x);
        perm[0][M-x+1] = M-i;
    }
    for(int i = 1; i < 31; i++)
        for(int j = 1; j <= M; j++)
            perm[i][j] = perm[i-1][perm[i-1][j]];

    for(int qq = 0; qq < Q; qq++){
        int x; scanf("%d", &x);
        x = N+1-x ;
        int bot = min(N, x+M-1); int mask = 0;
        int now = bot-x+1; int num = bot-M;
        for(int i = 30; i >- 1; i--)
            if(num >= (1<<i) && perm[i][now] > 0){
                now = perm[i][now];
                mask ^= (1<<i);
                num -= (1<<i);
            }
        mask++; now = perm[0][now] ;
        cout << bot-mask-now+1 << '\n';
    }
    return 0;
}
