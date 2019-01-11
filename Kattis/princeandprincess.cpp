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

int kase, N, p, q;
map<int, int> relabel;
vector<int> arr, lis;

int main(){
    //freopen("fortmoo.in", "r", stdin); freopen("fortmoo.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> N >> p >> q; relabel.clear();
        arr.clear(); lis.clear();
        for(int i = 0; i < p+1; i++){
            int x; cin >> x;
            relabel[x] = i;
        }
        for(int i = 0; i < q+1; i++){
            int x; cin >> x;
            if(relabel.find(x) != relabel.end()) arr.push_back(relabel[x]);
        }
        lis.push_back(arr[0]);
        for(int i = 1; i < arr.size(); i++){
            if(lis.back() < arr[i]) lis.push_back(arr[i]);
            else{
                auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
                *it = arr[i];
            }
        }
        cout << "Case " << kk << ": " << lis.size() << '\n';
    }
    return 0;
}
