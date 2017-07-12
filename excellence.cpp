#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string.h>

using namespace std;

int main(){
    int n, mini = 2000001, arr [100000]; scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr, arr+n);
    for(int i = 0; i < n/2; i++) mini = min(mini, arr[i]+arr[n-1-i]);
    cout << mini << '\n';
    return 0;
}
