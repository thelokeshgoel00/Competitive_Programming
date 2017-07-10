#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

int numCars;
double pos [100010], speed [100010], ret = 0.0, fast = 0.0;

int main(){
    cin >> numCars; pos[numCars] = 0; speed[numCars] = -1;
    for(int i = 0; i < numCars; i++) cin >> pos[i] >> speed[i];
    for(int i = 0; i < numCars; i++){
        fast = max(fast, speed[i]);
        ret += (pos[i]-pos[i+1])/fast;
    }
    printf("%lf\n", ret);
    return 0;
}
