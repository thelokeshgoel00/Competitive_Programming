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
#include <sstream>
#include <bitset>
#include <math.h>
#include <assert.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
template <class T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
 
#define PI atan2(0, -1)
#define epsilon 1e-9
#define INF 5000000000000000000
#define MOD 1000000007
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
int kase;
string ori;

int operValue(char c){ 
    if(c == '^') return 3;
    if(c == '*' || c == '/')  return 2;
    if(c == '+' || c == '-') return 1;
    return -1; 
}

string infixToPostfix(string s){
    stack<char> st; st.push('N'); 
    int L = s.length(); string ret = "";
    for(int i = 0; i < L; i++){ 
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')) ret += s[i]; 
        else if(s[i] == '(') st.push('('); 
        else if(s[i] == ')'){ 
            while(st.top() != 'N' && st.top() != '('){
                char c = st.top(); st.pop();
                ret += c;
            }
            st.pop();
        } 
        else{ 
            while(st.top() != 'N' && operValue(s[i]) <= operValue(st.top())){ 
                char c = st.top(); 
                st.pop(); 
                ret += c; 
            } 
            st.push(s[i]); 
        }
    } 
    while(st.top() != 'N'){ 
        char c = st.top(); st.pop(); 
        ret += c; 
    } 
    return ret;
}
 
int main(){
    //freopen("moofest.in", "r", stdin); freopen("moofest.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> kase;
    for(int kk = 1; kk <= kase; kk++){
        cin >> ori;
        cout << infixToPostfix(ori) << '\n';
    }
    return 0;
}
 
/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
