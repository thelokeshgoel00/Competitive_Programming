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

int n, k, ret, parent, grandparent, tree [1000010], nodes [1010];

int main(){
    while(true){
        cin >> n >> k;
        if(n == 0 && k == 0) break;
        int parentIndex = -1;
        memset(tree, 0, sizeof(tree)); memset(nodes, 0, sizeof(nodes));
        for(int i = 0; i < n; i++){
            int node; cin >> node;
            nodes[i] = node;
            if(i == 0) tree[node] = 0;
            else if(nodes[i] > nodes[i-1]+1) parentIndex++;
            if(i != 0) tree[node] = nodes[parentIndex];
        }
        parent = tree[k], grandparent = tree[parent];
        if(parent == 0 || grandparent == 0){ cout << "0\n"; continue; }
        ret = 0;
        for(int i = 0; i < 1000010; i++)
            if(tree[i] != parent && tree[tree[i]] == grandparent)
                ret++;
        cout << ret << '\n';
    }
    return 0;
}
