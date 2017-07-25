#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

#define PI 3.14159265

int numCows, ret = 0;
double R;
vector<pair<double, double>> ranges;
priority_queue<double, vector<double>, greater<double>> pq;

int main(){
    freopen("sight.in", "r", stdin); freopen("sight.out", "w", stdout);
    scanf("%d %lf", &numCows, &R);
    for(int i = 0; i < numCows; i++){
        double x, y; scanf("%lf %lf", &x, &y);
        double diff = acos(R/sqrt(pow(x, 2)+pow(y, 2)));
        double mini = atan2(y, x)-diff;
        if(mini < 0) mini += 2*PI;
        ranges.push_back(make_pair(mini, mini+2*diff));
    }
    sort(ranges.begin(), ranges.end());
    for(int i = 0; i < numCows; i++){
        while(pq.size() > 0 && pq.top() < ranges[i].first) pq.pop();
        pq.push(ranges[i].second);
        ranges[i].first += 2*PI; ranges[i].second += 2*PI;
    }
    for(int i = 0; i < numCows; i++){
        while(pq.size() > 0 && pq.top() < ranges[i].first) pq.pop();
        ret += pq.size();
        pq.push(ranges[i].second);
        ranges[i].first += 2*PI; ranges[i].second += 2*PI;
    }
    cout << ret << endl;
    return 0;
}
