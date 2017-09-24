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

int N, numPlayers = 0, numRatings = 0, ratings [1000010], tree [1000010], ratingToPlayer [1000010], playerToRating [1000010];
unordered_map<int, int> ratingToIndex;
pair<char, pair<int, int>> queries [1000010];

void add(int pos, int x){
    while(pos < 1000010){
        tree[pos] += x;
        pos += (pos&-pos);
    }
}

int query(int ranky){
    int curPos = 0; ranky = numPlayers-ranky+1;
    for(int i = 19; i > -1; i--)
        if(tree[curPos+(1<<i)] < ranky){
            curPos += (1<<i);
            ranky -= tree[curPos];
        }
    //cout << curPos << endl;
    return curPos+1;
}

int main(){
    //freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        char c [5]; int a, b; scanf("%s", &c);
        queries[i].first = c[0];
        if(c[0] == 'Q'){ scanf("%d", &a); queries[i].second.first = a; }
        else{
            scanf("%d %d", &a, &b); ratings[numRatings] = b; numRatings++;
            queries[i].second.first = a; queries[i].second.second = b;
        }
    }
    sort(ratings, ratings+numRatings); memset(tree, 0, sizeof(tree));
    for(int i = 0; i < numRatings; i++) ratingToIndex[ratings[i]] = i+1;
    for(int i = 0; i < N; i++){
        if(queries[i].first == 'Q') printf("%d\n", ratingToPlayer[query(queries[i].second.first)]);
        else{
            queries[i].second.second = ratingToIndex[queries[i].second.second];
            if(queries[i].first == 'M'){ int rat = playerToRating[queries[i].second.first]; add(rat, -1); }
            else numPlayers++;
            ratingToPlayer[queries[i].second.second] = queries[i].second.first;
            playerToRating[queries[i].second.first] = queries[i].second.second;
            add(queries[i].second.second, 1);
        }
    }
    return 0;
}
