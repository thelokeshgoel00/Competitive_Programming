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

int main(){
    long long temp;
    while(true){
        cin >> temp;
        if(temp == 0ll) break;
        cout << (temp+1)*(temp+2)*(temp)/6 << '\n';
        // https://math.stackexchange.com/questions/376284/sum-of-the-first-n-triangular-numbers-induction
    }
    return 0;
}
