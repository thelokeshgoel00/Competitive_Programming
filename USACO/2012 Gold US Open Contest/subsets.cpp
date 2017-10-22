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

int N, p = 0, q = 0;
vector<int> leftCows, rightCows;
vector<pair<int, int>> leftFreq, rightFreq;
set<int> goodMasks;

vector<pair<int, int>> processIt(vector<int> cows){
    set<pair<int, int>> temp;
    for(int mask = 0; mask < (1<<(cows.size())); mask++)
        for(int nmask = mask; ; nmask = (nmask-1)&mask){
            int sum = 0;
            for(int i = 0; i < cows.size(); i++){
                if((nmask&(1<<i)) > 0) sum -= cows[i];
                else if((mask&(1<<i)) > 0) sum += cows[i];
            }
            if(sum >= 0) temp.insert(make_pair(sum, mask));
            if(nmask == 0) break;
        }
    vector<pair<int, int>> legit; for(pair<int, int> a : temp) legit.push_back(a);
    return legit;
}

int main(){
    freopen("subsets.in", "r", stdin); freopen("subsets.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        if(i%2 == 1) leftCows.push_back(x);
        else rightCows.push_back(x);
    }
    leftFreq = processIt(leftCows); rightFreq = processIt(rightCows);
    while (p < leftFreq.size() && q < rightFreq.size()){
        if(leftFreq[p].first < rightFreq[q].first) p++;
        else if(leftFreq[p].first > rightFreq[q].first) q++;
        else{
            int p2 = p, q2 = q;
            while(p2 < leftFreq.size() && leftFreq[p2].first == leftFreq[p].first) p2++;
            while (q2 < rightFreq.size() && rightFreq[q2].first == rightFreq[q].first) q2++;
            for(int i = p; i < p2; i++)
                for(int j = q; j < q2; j++)
                    goodMasks.insert((leftFreq[i].second) | (rightFreq[j].second<<11));
            p = p2;
            q = q2;
        }
    }
    cout << goodMasks.size()-1 << '\n';
    return 0;
}
