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
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
struct Node{
    Node* child [26];
    pair<int, int> best;
    Node(){
        for(int i = 0; i < 26; i++) child[i] = NULL;
        best.f = best.s = MOD;
    }
    void place(string x, int index, int id){
        if(best.f == MOD) best.f = id;
        else if(best.s == MOD) best.s = id;
        if(index < 0) return;
        int temp = x[index]-'a';
        if(child[temp] == NULL) child[temp] = new Node();
        child[temp]->place(x, index-1, id);
    }
};
 
 
int N, trie ;
string s;
vector<string> wordList;
Node root;
 
string solveIt(){
    Node curr = root;
    for(int i = s.length()-1; i > -1; i--){
        Node nexty = *curr.child[s[i]-'a'];
        if(nexty.best.s == MOD){
            if(s.compare(wordList[curr.best.f]) == 0) return wordList[curr.best.s];
            else return wordList[curr.best.f];
        }
		    curr = nexty;
    }
	  if(s.compare(wordList[curr.best.f]) == 0) return wordList[curr.best.s];
    else return wordList[curr.best.f];
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    while(true){
        getline(cin, s);
        if(s.length() == 0) break;
        wordList.pb(s);
    }
    N = wordList.size(); sort(wordList.begin(), wordList.end());
    for(int i = 0; i < N; i++) root.place(wordList[i], wordList[i].length()-1, i);
    while(cin >> s){
        if(s.compare("Z") == 0) break;
        cout << solveIt() << '\n';
    }
    return 0;
}
 
/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
