#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string.h>
#include <math.h>

using namespace std;

int vals [] = {500, 100, 50, 20, 10, 5, 1}, billsA [7], billsB [7], owed;
bool aReach [22000], bReach [22000];

int main(){
    for(int i = 0; i < 7; i++) cin >> billsA[i];
    for(int i = 0; i < 7; i++) cin >> billsB[i];
    cin >> owed;
    memset(aReach, false, sizeof(aReach)); memset(bReach, false, sizeof(bReach));
    aReach[0] = bReach[0] = true;
    for(int k = 0; k < 7; k++){
        for(int i = 21000; i > -1; i--){
            if(!aReach[i]) continue;
            for(int j = 1; j <= billsA[k]; j++) aReach[i+j*vals[k]] = true;
        }
        for(int i = 21000; i > -1; i--){
            if(!bReach[i]) continue;
            for(int j = 1; j <= billsB[k]; j++) bReach[i+j*vals[k]] = true;
        }
    }
    for(int i = max(0, owed); i < 21000; i++)
        if(aReach[i] && bReach[i-owed]){
            cout << "YES\n";
            return 0;
        }
    cout << "NO\n";
    return 0;
}
