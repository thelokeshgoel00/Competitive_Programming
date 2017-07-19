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

int n;
bool isVamp [1000501];

bool vampCheck(int x){
    int check [10]; memset(check, 0, sizeof(check));
    int temp = x;
    while(temp > 0){
        check[temp%10]++;
        temp /= 10;
    }
    for(int i = 1; i*i <= x; i++){
        if(x%i != 0) continue;
        int freq [10]; memset(freq, 0, sizeof(freq));
        int temp1 = i; int temp2 = x/i;
        while(temp1 > 0){
            freq[temp1%10]++;
            temp1 /= 10;
        }
        while(temp2 > 0){
            freq[temp2%10]++;
            temp2 /= 10;
        }
        bool flag = true;
        for(int j = 0; j < 10; j++)
            if(freq[j] != check[j]){ flag = false; break; }
        if(flag) return true;
    }
    return false;
}

int main(){
    for(int i = 10; i <= 1000500; i++) isVamp[i] = vampCheck(i);
    while(true){
        cin >> n;
        if(n == 0) break;
        while(!isVamp[n]) n++;
        cout << n << '\n';
    }
    return 0;
}
