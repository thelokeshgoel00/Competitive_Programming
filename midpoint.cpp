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

int n;
long long arr [100010], low, high, lowret = 2e18, highret = -2e18;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    low = -2e18-1, high = arr[0]-1;
    while(low <= high){
        long long mid = (low+high)/2, curPoint = mid;
        bool flag = true;
        for(int i = 0; i < n-1; i++){
            long long nextPoint = 2ll*arr[i]-curPoint;
            if(nextPoint >= arr[i+1]){ flag = false; break; }
            curPoint = nextPoint;
        }
        if(flag){ lowret = min(lowret, mid); highret = max(highret, mid); high = mid-1; }
        else low = mid+1;
    }
    /*
    low = -2e18-1, high = arr[0]-1;
    while(low <= high){
        long long mid = (low+high)/2, curPoint = mid;
        bool flag = true;
        for(int i = 0; i < n-1; i++){
            long long nextPoint = 2ll*arr[i]-curPoint;
            if(nextPoint >= arr[i+1]){ flag = false; break; }
            curPoint = nextPoint;
        }
        if(flag){ highret = mid; low = mid+1; }
        else high = mid-1;
    }
    */
    if(lowret == 2e18) cout << "-1\n";
    else cout << lowret << " " << highret << '\n';
}
