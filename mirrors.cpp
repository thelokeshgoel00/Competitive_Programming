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

int checkIt(int diff){
    int ret = 1;
    for(int i = 1; i < a+b; i++){
        if(places[i].second != places[i-1].second && (places[i].first-places[i-1].first)%(2*diff) == diff) continue;
        if(places[i].second == places[i-1].second && (places[i].first-places[i-1].first)%(2*diff) == 0) continue;
        ret = 2; break;
    }
    return ret;
}

int main(){
    cin >> n; cin >> a;
    for(int i = 0; i < a; i++){ int x; cin >> x; places.push_back(make_pair(x, 0)); }
    cin >> b;
    for(int i = 0; i < b; i++){ int x; cin >> x; places.push_back(make_pair(x, 1)); }
    sort(places.begin(), places.end());
    if(a+b < 2){ cout << a+b << "\n"; return 0; }
    int maxDiff = places[0].first; int display = 2;
    for(int i = 1; i*i <= maxDiff; i++){
        if(maxDiff%i != 0) continue;
        display = min(display, checkIt(maxDiff/i));
        display = min(display, checkIt(i));
    }
    cout << display << '\n';
    return 0;
}
