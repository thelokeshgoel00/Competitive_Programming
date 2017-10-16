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
#include <math.h>

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int rows, cols, freq [26], groups [5], filled = 0;
string s;

int main(){
    //freopen("roboherd.in", "r", stdin); freopen("roboherd.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> rows >> cols; getline(cin, s);
    for(int i = 0; i < rows; i++){
        string s; getline(cin, s);
        for(int j = 0; j < cols; j++) freq[s[j]-'a']++;
    }
    for(int i = 1; i <= rows; i++)
        for(int j = 1; j <= cols; j++){
            if(i > (rows+1)/2 || j > (cols+1)/2) continue;
            int temp = 1;
            if(i != (rows+1)/2 || rows%2 == 0) temp++;
            if(j != (cols+1)/2 || cols%2 == 0) temp++;
            if(temp == 3) temp++;
            groups[temp]++;
        }
    sort(freq, freq+26);
    for(int i = 25; i > -1; i--)
        for(int j = 4; j > 0; j--){
            while(freq[i] >= j && groups[j] > 0){
                freq[i] -= j; groups[j]--;
                filled += j;
            }
        }
    if(filled == rows*cols) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
