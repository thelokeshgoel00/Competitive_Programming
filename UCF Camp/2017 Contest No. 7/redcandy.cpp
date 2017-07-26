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
        int ret = 0, num; cin >> num;
        for(int i = 0; i < num; i++){ int x; cin >> x; ret = max(ret, x); }
        cout << ret << '\n';
    }
    return 0;
}
