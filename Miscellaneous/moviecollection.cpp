#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <string.h>

using namespace std;

int kase, movies, queries, nextWhen, when [100001], tree [200006];

void add(int pos, int add){
    while(pos < 200006){
        tree[pos] += add;
        pos += (pos&-pos);
    }
}

int query(int pos){
    int sum = 0;
    while(pos > 0){
        sum += tree[pos];
        pos -= (pos&-pos);
    }
    return sum;
}

int main(){
    scanf("%d", &kase);
    for(int kk = 1; kk <= kase; kk++){
        scanf("%d %d", &movies, &queries);
        memset(tree, 0, sizeof(tree)); nextWhen = 100002;
        for(int i = 1; i <= movies; i++){
            when[i] = nextWhen+i;
            add(when[i], 1);
        }
        for(int i = 1; i <= queries; i++){
            int temp; scanf("%d", &temp);
            cout << query(when[temp])-1;
            if(i == queries) cout << '\n';
            else cout << ' ';
            add(when[temp], -1);
            when[temp] = nextWhen--;
            add(when[temp], 1);
        }
    }
    return 0;
}
