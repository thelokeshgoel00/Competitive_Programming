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

int N, rectangles [25010][4], ret;
bool bad [25010];
pair<pair<int, int>, int> corners [100010];

void processVertical(){
    sort(corners, corners+(4*N));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < 4; j += 2){
            auto it1 = lower_bound(corners, corners+(4*N), make_pair(make_pair(rectangles[i][j], rectangles[i][1]), 0));
            auto it2 = lower_bound(corners, corners+(4*N), make_pair(make_pair(rectangles[i][j], rectangles[i][3]), N));
            while(it1 != it2){
                if((*it1).second != i){
                    bad[i] = true;
                    bad[(*it1).second] = true;
                }
                it1++;
            }
        }
}

void processHorizontal(){
    for(int i = 0; i < 4*N; i++) swap(corners[i].first.first, corners[i].first.second);
    sort(corners, corners+(4*N));
    for(int i = 0; i < N; i++)
        for(int j = 1; j < 4; j += 2){
            auto it1 = lower_bound(corners, corners+(4*N), make_pair(make_pair(rectangles[i][j], rectangles[i][0]), 0));
            auto it2 = lower_bound(corners, corners+(4*N), make_pair(make_pair(rectangles[i][j], rectangles[i][2]), N));
            while(it1 != it2){
                if((*it1).second != i){
                    bad[i] = true;
                    bad[(*it1).second] = true;
                }
                it1++;
            }
        }
}

int main(){
    //freopen("photo.in", "r", stdin); freopen("photo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; memset(bad, false, sizeof(bad));
    for(int i = 0; i < N; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        rectangles[i][0] = a; rectangles[i][1] = b; rectangles[i][2] = c; rectangles[i][3] = d;
        corners[4*i] = make_pair(make_pair(a, b), i); corners[4*i+1] = make_pair(make_pair(a, d), i);
        corners[4*i+2] = make_pair(make_pair(c, b), i); corners[4*i+3] = make_pair(make_pair(c, d), i);
    }
    processVertical(); processHorizontal(); ret = N;
    for(int i = 0; i < N; i++)
        if(bad[i])
            ret--;
    cout << ret << '\n';
    return 0;
}
