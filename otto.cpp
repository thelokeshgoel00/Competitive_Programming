#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
double ret = 0.0, curSpeed;
pair<double, double> cars [100005];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%lf %lf", &cars[i].first, &cars[i].second);
    cars[n] = make_pair(0.0, 0.0);
    curSpeed = cars[0].second;
    for(int i = 1; i <= n; i++){
        ret += (cars[i-1].first-cars[i].first)/curSpeed;
        curSpeed = max(curSpeed, cars[i].second);
    }
    printf("%.6lf\n", ret);
    return 0;
}
