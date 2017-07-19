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
long long arr [100010], low, high, templo, temphi;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    low = arr[n-2]+1; high = arr[n-1]-1;
    for(int i = n-2; i > 0; i--){
        templo = low, temphi = high;
        low = 2*arr[i]-temphi; high = 2*arr[i]-templo;
        low = max(low, arr[i-1]+1);
        if(low > high){ cout << "-1\n"; return 0; }
    }
    templo = low, temphi = high;
    low = 2*arr[0]-temphi; high = 2*arr[0]-templo;
    cout << low << " " << high << '\n';
    return 0;
}
