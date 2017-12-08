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

#define PI 3.14159265358979
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, x, arr [100010], prevs [100010];
vector<pair<int, int>> lis;
stack<int> toPrint;

int main(){
    //freopen("trapped.in", "r", stdin); freopen("trapped.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    while(cin >> N){
        memset(prevs, -1, sizeof(prevs)); lis.clear();
        for(int i = 0; i < N; i++) cin >> arr[i];
        lis.push_back(make_pair(arr[0], 0));
        for(int i = 1; i < N; i++){
            if(arr[i] > lis.back().first){
                prevs[i] = lis.back().second;
                lis.push_back(make_pair(arr[i], i));
            }
            else if(arr[i] < lis.front().first){ lis.front().first = arr[i]; lis.front().second = i; }
            else{
                auto it = lower_bound(lis.begin(), lis.end(), make_pair(arr[i], i)); it--;
                if((*it).first >= arr[i]) continue;
                prevs[i] = (*it).second;  it++;
                (*it).first = arr[i]; (*it).second = i;
            }
        }
        for(int i = lis.back().second; i > -1; i = prevs[i]) toPrint.push(i);
        cout << lis.size() << '\n';
        for(int i = 0; i < lis.size(); i++){
            cout << toPrint.top(); toPrint.pop();
            if(toPrint.size() > 0) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
