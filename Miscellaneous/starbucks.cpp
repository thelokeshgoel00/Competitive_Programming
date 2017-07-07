#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int main(){
    //freopen("shufflegold.in","r",stdin); freopen("shufflegold.out","w",stdout);
    int a, b, c; cin >> a >> b >> c; int ret = 0;
    for(int i = 0; i <= c/a; i++)
        if((c - i*a)%b == 0) ret++;
    cout << ret << '\n';
    return 0;
}
