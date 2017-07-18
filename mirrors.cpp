#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <string.h>

using namespace std;

int n, a, b;
vector<pair<int, int>> places;

int main(){
    cin >> n; cin >> a;
    for(int i = 0; i < a; i++){ int x; cin >> x; places.push_back(make_pair(x, 0)); }
    cin >> b;
    for(int i = 0; i < b; i++){ int x; cin >> x; places.push_back(make_pair(x, 1)); }
    sort(places.begin(), places.end());
    if(a+b < 2){ cout << a+b << "\n"; return 0; }
    int diff = places[1].first-places[0].first;
    if(places[0].second == places[1].second){
        if(diff%2 == 1){ cout << "2\n"; return 0; }
        diff /= 2;
    }
    if(diff == 0){ cout << "2\n"; return 0; }
    int ret = 1;
    for(int i = 2; i < a+b; i++){
        if(places[i].second != places[i-1].second && places[i].first-places[i-1].first == diff) continue;
        if(places[i].second == places[i-1].second && places[i].first-places[i-1].first == 2*diff) continue;
        ret = 2; break;
    }
    cout << ret << '\n';
    return 0;
}
