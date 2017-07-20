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

int n;
vector<int> stuff;

bool checkIt(int now){
    for(int i = 2; i*i <= now; i++)
        if(now%i == 0)
            return false;
    return true;
}

void generateThem(int now){
    stuff.push_back(now);
    for(int i = 1; i < 10; i += 2){
        int next = now*10+i;
        if(checkIt(next)) generateThem(next);
    }
}

int main(){
    cin >> n;
    generateThem(2); generateThem(3); generateThem(5); generateThem(7);
    sort(stuff.begin(), stuff.end());
    cout << stuff[n-1] << '\n';
    return 0;
}
