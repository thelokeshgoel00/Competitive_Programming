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

int kase, rows, cols, arr [1050][1050], tree [1050][1050];

void add(int r, int c, int x){
    for(int i = r; i <= rows; i += (i&-i))
        for(int j = c; j <= cols; j += (j&-j))
            tree[i][j] += x;
}

int query(int r, int c){
    int ret = 0;
    for(int i = r; i > 0; i -= (i&-i))
        for(int j = c; j > 0; j -= (j&-j))
            ret += tree[i][j];
    return ret;
}

int main(){
    //freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    scanf("%d", &kase);
    for(int kk = 1; kk <= kase; kk++){
        memset(arr, 0, sizeof(arr)); memset(tree, 0, sizeof(tree)); scanf("%d", &rows); cols = rows;
        while(true){
            char temp [5]; scanf("%s", &temp);
            string cmd(temp);
            if(cmd.compare("END") == 0) break;
            if(cmd.compare("SET") == 0){
                int a, b, c; scanf("%d %d %d", &a, &b, &c);
                add(a+1, b+1, -arr[a][b]+c); arr[a][b] = c;
            }
            else{
                int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d); c++; d++;
                printf("%d\n", query(c, d)-query(a, d)-query(c, b)+query(a, b));
            }
        }
    }
    return 0;
}
