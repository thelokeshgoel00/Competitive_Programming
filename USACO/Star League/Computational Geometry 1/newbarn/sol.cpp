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

int N, numGood, dx [] = {1, 0, -1, 0}, dy [] = {0, 1, 0, -1}, tests [4]; ;
pair<int, int> points [25010], xMed, yMed;

void getXMed(){
    sort(points, points+N);
    if(N%2 == 0){ xMed.first = points[N/2-1].first; xMed.second = points[N/2].first; }
    else{ xMed.first = points[N/2].first; xMed.second = points[N/2].first; }
}

void getYMed(){
    for(int i = 0; i < N; i++) swap(points[i].first, points[i].second);
    sort(points, points+N);
    for(int i = 0; i < N; i++) swap(points[i].first, points[i].second);
    if(N%2 == 0){ yMed.first = points[N/2-1].second; yMed.second = points[N/2].second; }
    else{ yMed.first = points[N/2].second; yMed.second = points[N/2].second; }
}

int computeCost(int x, int y){
    int ret = 0;
    for(int i = 0; i < N; i++) ret += abs(points[i].first-x)+abs(points[i].second-y);
    return ret;
}

int main(){
    //freopen("photo.in", "r", stdin); freopen("photo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> points[i].first >> points[i].second;
    getXMed(); getYMed(); numGood = (xMed.second-xMed.first+1)*(yMed.second-yMed.first+1);
    for(int i = 0; i < N; i++)
        if(points[i].first >= xMed.first && points[i].first <= xMed.second)
            if(points[i].second >= yMed.first && points[i].second <= yMed.second)
                numGood--;
    if(numGood == 0){
        for(int i = 0; i < 4; i++) tests[i] = computeCost(xMed.first+dx[i], yMed.first+dy[i]);
        sort(tests, tests+4);
        if(tests[3] == tests[0]) numGood = 4;
        else if(tests[2] == tests[0]) numGood = 3;
        else if(tests[1] == tests[0]) numGood = 2;
        else numGood = 1;
    }
    else tests[0] = computeCost(xMed.first, yMed.first);
    cout << tests[0] << " " << numGood << '\n';
    return 0;
}
