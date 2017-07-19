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

bool check(string x){
    for(int i = 0; i < x.length()/2; i++)
        if(x[i] != x[x.length()-1-i])
            return false;
    return true;
}

string simulate(string x){
    bool carry = true;
    for(int i = x.length()-1; i > -1; i--){
        if(x[i] == '9') x[i] = '0';
        else{ x[i]++; break; }
    }
    return x;
}

int main(){
    string s;
    while(true){
        cin >> s;
        if(s.compare("0") == 0) break;
        int add = 0;
        while(!check(s)){
            add++;
            s = simulate(s);
        }
        cout << add << '\n';
    }
    return 0;
}
