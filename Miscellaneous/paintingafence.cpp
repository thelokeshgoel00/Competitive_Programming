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

int N, curID = 0, ret = 400;
map<string, int> colorToID;
vector<pair<pair<int, int>, int>> intervals;

int main(){
    //freopen("roboherd.in", "r", stdin); freopen("roboherd.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 0; i < N; i++){
        string s; int a, b; cin >> s >> a >> b;
        if(colorToID.find(s) == colorToID.end()){ colorToID[s] = curID; curID++; }
        intervals.push_back(make_pair(make_pair(a, b), colorToID[s]));
    }
    sort(intervals.begin(), intervals.end()); curID = max(curID, 3);
    for(int a = 0; a < curID; a++)
        for(int b = a+1; b < curID; b++)
            for(int c = b+1; c < curID; c++){
                int lowestNotTaken = 1, idx = 0, taken = 0;
                vector<pair<int, int>> consider;
                for(int i = 0; i < N; i++)
                    if(intervals[i].second == a || intervals[i].second == b || intervals[i].second == c)
                        consider.push_back(intervals[i].first);
                 while(idx < consider.size() && lowestNotTaken < 10001){
                    if(consider[idx].first > lowestNotTaken){ lowestNotTaken = 1; break; }
                    int tempMax = consider[idx].second;
                    while(idx < consider.size()-1 && consider[idx+1].first <= lowestNotTaken){
                        tempMax = max(tempMax, consider[idx+1].second);
                        idx++;
                    }
                    if(tempMax >= lowestNotTaken){ lowestNotTaken = tempMax+1; taken++; }
                    idx++;
                }
                if(lowestNotTaken == 10001) ret = min(ret, taken);
            }
    if(ret == 400) cout << "IMPOSSIBLE\n";
    else cout << ret << '\n';
    return 0;
}
