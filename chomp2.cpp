#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string.h>

using namespace std;

int nums, ret, stuff [100001], bestLeft [100001], bestRight [100001];

int main(){
    int nums; scanf("%d", &nums);
    for(int i = 0; i < nums; i++) scanf("%d", &stuff[i]);
    int curSum = 0, bestSum = 0;
    for(int i = 0; i < nums; i++){
        curSum += stuff[i];
        bestSum = max(bestSum, curSum);
        curSum = max(curSum, 0);
        bestLeft[i] = bestSum;
    }
    curSum = 0, bestSum = 0;
    for(int i = nums-1; i > -1; i--){
        curSum += stuff[i];
        bestSum = max(bestSum, curSum);
        curSum = max(curSum, 0);
        bestRight[i] = bestSum;
    }
    ret = max(0, bestLeft[nums-1]);
    for(int i = 0; i < nums-1; i++) ret = max(ret, bestLeft[i]+bestRight[i+1]);
    cout << ret << '\n';
    return 0;
}
