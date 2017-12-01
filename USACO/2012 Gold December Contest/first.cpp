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
#include <cstring>
#include <sstream>
#include <math.h>

using namespace std;

#define PI 4.0*atan(1.0)
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, idx = 1, trie [300010][26], inDegree [26];
string arr [30010];
bool isEnd [300010], adjacency [26][26];
vector<string> ret;

int main(){
    freopen("first.in", "r", stdin); freopen("first.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N; memset(trie, -1, sizeof(trie)); memset(isEnd, false, sizeof(isEnd));
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        int pos = 0;
        for(int j = 0; j < arr[i].length(); j++){
            if(trie[pos][arr[i][j]-'a'] == -1) trie[pos][arr[i][j]-'a'] = idx++;
            pos = trie[pos][arr[i][j]-'a'];
        }
        isEnd[pos] = true;
    }
    for(int i = 0; i < N; i++){
        memset(adjacency, false, sizeof(adjacency)); memset(inDegree, 0, sizeof(inDegree));
        int pos = 0; bool endFound = false;
        for(int j = 0; j < arr[i].length(); j++){
            if(isEnd[pos]){ endFound = true; break; }
            for(int k = 0; k < 26; k++)
                if(trie[pos][k] != -1 && arr[i][j]-'a' != k)
                    adjacency[arr[i][j]-'a'][k]++;
            pos = trie[pos][arr[i][j]-'a'];
        }
        if(endFound) continue; // Another string is the prefix of this string, so this string can never be lexicographically first
        for(int a = 0; a < 26; a++)
            for(int b = 0; b < 26; b++)
                if(adjacency[a][b])
                    inDegree[b]++;
        int numZero = 0; queue<int> q;
        for(int a = 0; a < 26; a++)
            if(inDegree[a] == 0)
                q.push(a);
        while(q.size() > 0){
            int curr = q.front(); q.pop(); numZero++;
            for(int a = 0; a < 26; a++)
                if(adjacency[curr][a] && inDegree[a] > 0){
                    inDegree[a]--;
                    if(inDegree[a] == 0) q.push(a);
                }
        }
        if(numZero < 26) continue; // The potential ordering of the alphabet contains a cycle
        /*bool hasCycle = false;
        for(int c = 0; c < 26; c++)
            for(int a = 0; a < 26; a++)
                for(int b = 0; b < 26; b++){
                    adjacency[a][b] |= adjacency[a][c] && adjacency[c][b];
                    if(a == b && adjacency[a][b]) hasCycle = true;
                }
        if(hasCycle) continue;*/
        ret.push_back(arr[i]);
    }
    cout << ret.size() << '\n';
    for(string s : ret) cout << s << '\n';
    return 0;
}

/*
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int N, degree [26], adjacency [26][26];
vector<string> ori, ret;

struct Node{
    Node* child [26];
    bool isEnd;
    Node(){
        for(int i = 0; i < 26; i++) child[i] = NULL;
        isEnd = false;
    }
    void place(string x, int index, int id){
        if(index == x.length()){ isEnd = true; return; }
        int temp = x[index]-'a';
        if(child[temp] == NULL) child[temp] = new Node();
        child[temp]->place(x, index+1, id);
    }
    bool dfs(string x, int index){
        if(index == x.length()) return true;
        if(isEnd) return false;
        int temp = x[index]-'a';
        for(int i = 0; i < 26; i++)
            if(i != temp && child[i] != NULL)
                adjacency[temp][i]= 1;
        return child[temp]->dfs(x, index+1);
    }
};

Node root;

bool isValid(){
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            if(adjacency[i][j])
                degree[j]++;
    queue<int> q; int counter = 0;
    for(int i = 0; i < 26; i++)
        if(degree[i] == 0) q.push(i);
    while(q.size() > 0){
        int now = q.front(); q.pop(); counter++;
        for(int i = 0; i < 26; i++)
            if(adjacency[now][i]){
                degree[i]--;
                if(degree[i] == 0) q.push(i);
            }
    }
    return counter == 26;
}

int main(){
    freopen("first.in", "r", stdin); freopen("first.out", "w", stdout);
    cin >> N;
    for(int i = 0; i < N; i++){
        string s; cin >> s; ori.push_back(s);
        root.place(s, 0, i);
    }
    for(int i = 0; i < N; i++){
        memset(adjacency, 0, sizeof(adjacency));
        memset(degree, 0, sizeof(degree));
        if(root.dfs(ori[i], 0) && isValid()) ret.push_back(ori[i]);
    }
    cout << ret.size() << '\n';
    for(int i = 0; i < ret.size(); i++) cout << ret[i] << '\n';
    return 0;
}
*/
