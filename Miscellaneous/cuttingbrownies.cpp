#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <deque>
#include <string.h>
#include <sstream>
#include <math.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

int kase;

int main(){
    //freopen("disrupt.in", "r", stdin); freopen("disrupt.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        int a, b, bita = 0, bitb = 0; string s; cin >> a >> b >> s;
        while(a > 0){
            bita++;
            a /= 2;
        }
        while(b > 0){
            bitb++;
            b /= 2;
        }
        if(s.compare("Harry") == 0){
            if(bitb > bita) cout << "Harry can win\n";
            else cout << "Harry cannot win\n";
        }
        else{
            if(bita > bitb) cout << "Vicky can win\n";
            else cout << "Vicky cannot win\n";
        }
    }
    return 0;
}
