#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string.h>
#include <math.h>

using namespace std;

int n, freq [50], ret = 50;

int solver(){
    vector<int> times;
    for(int i = 15; i <= 45; i++)
        for(int j = 0; j < freq[i]; j++)
            times.push_back(i);
    int low = 0, high = times.size()-1, counter = 0;
    while(low < high){
        if(times[low]+times[high] <= 45) low++;
        high--; counter++;
    }
    if(low == high) counter++;
    ret = min(ret, counter);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int kachow; cin >> kachow;
        freq[kachow]++;
    }
    while(freq[15] >= 0){ solver(); freq[15] -= 3; }
    cout << ret << '\n';
    return 0;
}
