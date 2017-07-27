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

#define MOD 1000000007

int kase, numBeans;
long long factorial [33], ret, leftWays [1<<16][17], rightWays [1<<16][17];
pair<long long, long long> target;

void fillMap(map<pair<long long, long long>, int> &stuff, vector<pair<long long, long long>> arr, long long ways [1<<16][17]){
    int n = arr.size(), id = 0;
    pair<long long, long long> subsets [1<<n];
    for(int mask = 0; mask < (1<<n); mask++){
        subsets[mask].first = subsets[mask].second = 0;
        for(int bit = 0; bit < n; bit++){
            if((mask&(1<<bit)) > 0){
                subsets[mask].first += arr[bit].first;
                subsets[mask].second += arr[bit].second;
            }
        }
    }
    for(int i = 0; i < (1<<n); i++)
        if(stuff.find(subsets[i]) == stuff.end())
            stuff.insert(make_pair(make_pair(subsets[i].first, subsets[i].second), id++));
    for(int i = 0; i < (1<<n); i++) {
        int index = stuff[subsets[i]];
        ways[index][__builtin_popcount(i)]++;
    }
}

int main(){
    cin >> kase; factorial[0] = 1;
    for(int i = 1; i < 33; i++) factorial[i] = (factorial[i-1]*(long long)i)%MOD;
    for(int kk = 1; kk <= kase; kk++){
        cin >> numBeans >> target.first >> target.second; ret = 0;
        vector<pair<long long, long long>> leftBeans, rightBeans;
        for(int i = 0; i < numBeans/2; i++){
            leftBeans.push_back(make_pair(-1000000001, -1000000001));
            cin >> leftBeans[i].first >> leftBeans[i].second;
        }
        for(int i = 0; i < numBeans-numBeans/2; i++){
            rightBeans.push_back(make_pair(-1000000001, -1000000001));
            cin >> rightBeans[i].first >> rightBeans[i].second;
        }
        map<pair<long long, long long>, int> leftMap, rightMap;
        memset(leftWays, 0, sizeof(leftWays)); memset(rightWays, 0, sizeof(rightWays));
        fillMap(leftMap, leftBeans, leftWays); fillMap(rightMap, rightBeans, rightWays);
        for(auto iter = leftMap.begin(); iter != leftMap.end(); iter++){
            pair<long long, long long> now = iter->first;
            pair<long long, long long> need; need.first = target.first-now.first; need.second = target.second-now.second;
            if(rightMap.find(need) == rightMap.end()) continue;
            int leftIndex = leftMap[now]; int rightIndex = rightMap[need];
            for(int i = 0; i < 17; i++){
                if(leftWays[leftIndex][i] == 0) continue;
                for(int j = 0; j < 17; j++){
                    int bits = i+j;
                    long long freq = leftWays[leftIndex][i]*rightWays[rightIndex][j];
                    ret = (ret+(freq%MOD)*factorial[bits])%MOD;
                }
            }
        }
        cout << ret << '\n';
    }
    return 0;
}
