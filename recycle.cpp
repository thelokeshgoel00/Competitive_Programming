#define __USE_MINGW_ANSI_STDIO 0
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

int main(){
    int kase; cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        int sum = 0, x;
        for(int i = 0; i < 16; i++){ cin >> x; sum += x; }
        cin >> x; cout << sum << '\n';
    }
    return 0;
}
