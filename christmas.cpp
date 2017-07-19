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
    }
    return 0;
}
