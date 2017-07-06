#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

int n, openLeft [1001], dp [1000][500];
string stuff;

int go(int i, int a){
    if(i == n) return 1;
    if(dp[i][a] > 0) return dp[i][a];
    int b = openLeft[i]-a; int ans = 0;
    if(stuff[i] == '(') ans = go(i+1, a)+go(i+1, a+1);
    else{
        if(a > 0) ans += go(i+1, a-1);
        if(b > 0) ans += go(i+1, a);
    }
    return dp[i][a] = ans%2012;
}

int main(){
    freopen("bbreeds.in", "r", stdin); freopen("bbreeds.out", "w", stdout);
    cin >> stuff; n = stuff.length();
    for(int i = 0; i < n; i++) openLeft[i+1] = openLeft[i] + (stuff[i] == '(' ? 1 : -1);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n/2; j++)
            dp[i][j] = -1;
    cout << go(0, 0) << endl;
    return 0;
}
