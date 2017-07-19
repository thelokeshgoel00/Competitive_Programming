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

int n, ordering, curPos, curAdd;
vector<string> toppings, ret;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        toppings.push_back(s);
    }
    sort(toppings.begin(), toppings.end());
    cin >> ordering;
    for(int i = n; i > 0; i--){
        if(((1<<i)&ordering) > 0) continue;
        int temp = ordering%(1<<i)-1;
        if(temp < 0) temp = (1<<i)-1;
        ordering = ordering/(1<<i)*(1<<i)+temp;
        //cout << ordering << '\n';
    }
    for(int i = 0; i < n; i++)
        if(((1<<(n-1-i))&ordering) == 0)
            ret.push_back(toppings[i]);
    cout << ret[0];
    for(int i = 1; i < ret.size(); i++) cout << " " << ret[i];
    cout << '\n';
    return 0;
}

/*
Alternate Method

#include <bits/stdc++.h>
 
using namespace std;
const int L = 60, N = 1e5;
typedef long long ll;
 
ll f[L];
char s[N];
int main(){
    f[0] = 1;
    for (int i = 1; i < L; ++ i)
        f[i] = f[i - 1] * 2LL;
    int n; cin >> n;
    for (int i = 0; i < n; ++ i)
        cin >> s[i];
    ll k; cin >> k;
    vector <int> ans;
    int cur_l = 0;
    while (k){
        while (k > f[n - cur_l - 1])
            k -= f[n - cur_l - 1], ++ cur_l;
        ans.push_back(cur_l), ++ cur_l, -- k;
    }
    for (auto i : ans) cout << s[i] << " ";
    return 0;
}
*/
