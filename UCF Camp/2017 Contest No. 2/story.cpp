#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string.h>

using namespace std;

#define MOD 1000000007

int numEvents, subtreeSizes [5001];
vector<int> satisfies [5001];
long long ret = 1ll, choose [5001][5001];

int findSubtreeSizes(int curr){
    int counter = 1;
    for(int i = 0; i < int(satisfies[curr].size()); i++) counter += findSubtreeSizes(satisfies[curr][i]);
    return subtreeSizes[curr] = counter;
}

void solve(int curr){
    int under = subtreeSizes[curr]-1;
    for(int i = 0; i < satisfies[curr].size(); i++){
        int next = satisfies[curr][i];
        ret = (ret*choose[under][subtreeSizes[next]])%MOD;
        solve(next);
        under -= subtreeSizes[next];
    }
}

int main(){
    memset(choose, 0ll, sizeof(choose)); choose[0][0] = 1ll;
    for(int i = 1; i < 5001; i++){
        choose[i][0] = 1ll;
        for(int j = 1; j <= i; j++){
            choose[i][j] = (choose[i-1][j]+choose[i-1][j-1])%MOD;
        }
    }
    scanf("%d", &numEvents);
    for(int i = 1; i < numEvents; i++){
        int temp; scanf("%d", &temp);
        satisfies[temp].push_back(i);
    }
    findSubtreeSizes(numEvents); solve(numEvents);
    cout << ret << '\n';
}
