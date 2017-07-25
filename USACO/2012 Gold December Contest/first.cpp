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
