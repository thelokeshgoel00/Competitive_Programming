/*
ID: vamaddu1
PROG: picture
LANG: C++11
*/


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

int N, freq [20010], ret = 0;
vector<pair<pair<int, int>, pair<int, int>>> horizontal, vertical;

int main(){
    freopen("picture.in", "r", stdin); freopen("picture.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        a += 10000; b += 10000; c += 10000; d += 10000;
        horizontal.push_back(make_pair(make_pair(b, -1), make_pair(a, c)));
        horizontal.push_back(make_pair(make_pair(d, 1), make_pair(a, c)));
        vertical.push_back(make_pair(make_pair(a, -1), make_pair(b, d)));
        vertical.push_back(make_pair(make_pair(c, 1), make_pair(b, d)));
    }
    sort(horizontal.begin(), horizontal.end());  memset(freq, 0, sizeof(freq));
    for(int i = 0; i < 2*N; i++)
      for(int pos = horizontal[i].second.first; pos < horizontal[i].second.second; pos++){
          if(horizontal[i].first.second == -1){
              if(freq[pos] == 0) ret++;
              freq[pos]++;
          }
          else{
              if(freq[pos] == 1) ret++;
              freq[pos]--;
          }
      }
    sort(vertical.begin(), vertical.end());  memset(freq, 0, sizeof(freq));
    for(int i = 0; i < 2*N; i++)
      for(int pos = vertical[i].second.first; pos < vertical[i].second.second; pos++){
          if(vertical[i].first.second == -1){
              if(freq[pos] == 0) ret++;
              freq[pos]++;
          }
          else{
              if(freq[pos] == 1) ret++;
              freq[pos]--;
          }
      }
    cout << ret << '\n';
    return 0;
}
