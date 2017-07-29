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

int numItems;
long long total, curItem;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main(){
    cin >> numItems >> curItem; total += curItem; pq.push(curItem);
    for(int i = 2; i <= numItems; i++){
        cin >> curItem;
        if(i%2 == 0 && i > 2){ total += curItem; pq.push(curItem); continue; }
        if(curItem > pq.top()){ total += curItem-pq.top(); pq.pop(); pq.push(curItem); }
    }
    cout << total << '\n';
    return 0;
}
