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

#define PI 3.141592653589793
#define epsilon 0.000000001
#define INF 1000000000000
#define MOD 1000000007

int N;
pair<long long, long long> jobs [100010];
long long ret = 0ll, tiempo = INF;
priority_queue<long long> profits;

int main(){
    //freopen("dec.in", "r", stdin); freopen("dec.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%lld %lld", &jobs[i].first, &jobs[i].second);
    jobs[N].first = jobs[N].second = 0ll;
    sort(jobs, jobs+N+1);
    for(int i = N; i > -1; i--){
        while(profits.size() > 0 && tiempo > jobs[i].first){
            tiempo--;
            ret += profits.top();
            profits.pop();
        }
        tiempo = jobs[i].first; profits.push(jobs[i].second);
    }
    cout << ret << '\n';
    return 0;
}
