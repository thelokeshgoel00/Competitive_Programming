#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <string.h>
#include <math.h>

using namespace std;

#define PI 3.141592653589793
#define epsilon 0.000000001

struct Item{
    long long val;
    int index;
    Item(long long x, int y){ val = x; index = y; }
    bool operator<(const Item &other) const{ return val > other.val; }
};

int N, K, ret = 0;
long long M;
vector<pair<long long, long long>> cows;
priority_queue<long long, vector<long long>, greater<long long>> savings;
priority_queue<Item> discounted, normal;
bool used [50010];

int main() {
    freopen("coupons.in", "r", stdin); freopen("coupons.out", "w", stdout);
    scanf("%d %d %lld", &N, &K, &M);
    for(int i = 0; i < N; i++){
        cows.push_back(make_pair(0, 0));
        scanf("%lld %lld", &cows[i].first, &cows[i].second);
        discounted.push(Item(cows[i].second, i)); normal.push(Item(cows[i].first, i));
    }
    memset(used, false, sizeof(used));
    for(int i = 0; i < K; i++) savings.push(0ll);
    while(M > 0ll && ret < N){
        while(used[discounted.top().index]) discounted.pop();
        while(used[normal.top().index]) normal.pop();
        long long pay = 0;
        if(savings.top()+discounted.top().val < normal.top().val){
            pay = discounted.top().val+savings.top();
            if(M < pay) break;
            M -= pay;
            savings.pop(); savings.push(cows[discounted.top().index].first-cows[discounted.top().index].second);
            used[discounted.top().index] = true;
        }
        else{
            pay = normal.top().val;
            if(M < pay) break;
            M -= pay;
            used[normal.top().index] = true;
        }
        ret++;
    }
    cout << ret << '\n';
    return 0;
}
