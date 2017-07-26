#define __USE_MINGW_ANSI_STDIO 0
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

int kase;
long long fx [1001];

//For odd x, f(x) = f(x-1)+f(x-2), number of tilings of a 3xN rectangle with a corner missing
//For even x, f(x) = 2*f(x-1)+f(x-2), number of tilings of a 3xN rectangle completely filled in
//https://cs.stackexchange.com/questions/42170/why-do-these-recurrences-determine-the-number-of-ways-of-tiling-a-3xn-rectangle

int main(){
    fx[0] = 1; fx[1] = 1; fx[2] = 3; fx[3] = 4;
    for(int i = 4; i < 1001; i++){
        if(i%2 == 1) fx[i] = fx[i-1]+fx[i-2];
        else fx[i] = 2*fx[i-1]+fx[i-2];
        fx[i] = fx[i]%1000000007;
    }
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        int x; cin >> x;
        cout << fx[x] << '\n';
    }
    return 0;
}
