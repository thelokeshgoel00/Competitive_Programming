#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int main(){
    int n, w, i; scanf("%d %d", &n, &w); int arr [n];
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr, arr+n); int sum = 0;
    for(i = 0; i < n; i++){
        sum += arr[i];
        if(sum > w) break;
    }
    cout << i << '\n';
    return 0;
}
