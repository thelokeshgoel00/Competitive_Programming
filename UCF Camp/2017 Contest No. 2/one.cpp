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
    int a, b, maxGCD = 1; scanf("%d %d", &a, &b);
    for(int i = 1; i <= b; i++){
        int lower = a/i;
        if(a%i != 0) lower++;
        int high = b/i;
        if(high-lower+1 > 1) maxGCD = i;
    }
    int ret = maxGCD;
    if(a%maxGCD == 0) ret = a;
    else ret *= (a/maxGCD+1);
    cout << ret << " " << ret+maxGCD << '\n';
    return 0;
}
