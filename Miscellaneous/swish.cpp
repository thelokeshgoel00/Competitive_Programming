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
#define INF 1000000000000000000
#define MOD 1000000007

int N, flipIndex [] = {9, 10, 11, 6, 7, 8, 3, 4, 5, 0, 1, 2}, dp [1500010];
int dots [4], rings [4], placed [12]; // 0 = empty, 1 = dot, 2 = ring, 3 = full
pair<int, int> cards [30];
vector<int> consider;

int getGroup(int pos){
    if(pos == 0 || pos == 2 || pos == 9 || pos == 11) return 0;
    if(pos == 3 || pos == 5 || pos == 6 || pos == 8) return 1;
    if(pos == 1 || pos == 10) return 2;
    return 3;
}

pair<int, int> rotateIt(pair<int, int> card){ return make_pair(11-card.first, 11-card.second); }
pair<int, int> flipIt(pair<int, int> card){ return make_pair(flipIndex[card.first], flipIndex[card.second]); }

bool recurseIt(int mask, int dotPos){
    if(mask == 0){
        for(int i = 0; i < 12; i++)
            if(placed[i] == 1 || placed[i] == 2)
                return false;
        return true;
    }
    if(placed[dotPos] == 3) return false;
    pair<int, int> tempCards [4];
    for(int i = 0; i < N; i++){
        if((mask&(1<<i)) == 0 || getGroup(cards[i].first) != getGroup(dotPos)) continue;
        tempCards[0] = cards[i]; tempCards[1] = rotateIt(tempCards[0]);
        tempCards[2] = flipIt(tempCards[0]); tempCards[3] = rotateIt(tempCards[2]);
        mask ^= (1<<i); placed[dotPos] ^= 2;
        for(int j = 0; j < 4; j++)
            if(tempCards[j].first == dotPos && placed[tempCards[j].second]%2 == 0){
                placed[tempCards[j].second] ^= 1;
                if(recurseIt(mask, tempCards[j].second)) return true;
                placed[tempCards[j].second] ^= 1;
            }
        mask ^= (1<<i); placed[dotPos] ^= 2;
    }
    return false;
}

bool isSwish(int mask){
    memset(rings, 0, sizeof(rings)); memset(dots, 0, sizeof(dots));
    for(int i = 0; i < N; i++)
        if((mask&(1<<i)) > 0){
            rings[getGroup(cards[i].first)]++;
            dots[getGroup(cards[i].second)]++;
        }
    if(dots[0] != rings[0] || dots[0] > 4) return false;
    if(dots[1] != rings[1] || dots[1] > 4) return false;
    if(dots[2] != rings[2] || dots[2] > 2) return false;
    if(dots[3] != rings[3] || dots[3] > 2) return false;
    memset(placed, 0, sizeof(placed));
    for(int i = 0; i < N; i++)
        if((mask&(1<<i)) > 0){
            placed[cards[i].first] = 2;
            placed[cards[i].second] = 1;
            return recurseIt(mask^(1<<i), cards[i].second);
        }
    return false;
}

int main(){
    //freopen("mowing.in", "r", stdin); freopen("mowing.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; fill(dp, dp+1500010, 30); dp[0] = 0; consider.push_back(0);
    for(int i = 0; i < N; i++) cin >> cards[i].first >> cards[i].second;
    for(int mask = 1; mask < (1<<N); mask++){
        if(!isSwish(mask)) continue;
        for(int i = consider.size()-1; i > -1; i--){
            int other = consider[i];
            if((mask&other) > 0) continue;
            if(dp[mask|other] == 30) consider.push_back(mask|other);
            dp[mask|other] = min(dp[mask|other], dp[other]+1);
        }
    }
    if(dp[(1<<N)-1] == 30) dp[(1<<N)-1] = -1;
    cout << dp[(1<<N)-1] << '\n';
    return 0;
}
