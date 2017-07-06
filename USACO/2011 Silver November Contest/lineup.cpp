#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>

using namespace std;

class Cow{
    public:
        int pos, id;
        Cow(): pos(-1), id(-1) {}
};

int sorter(const void* v1, const void *v2){
    Cow *c1 = (Cow*)v1, *c2 = (Cow*)v2;
    return c1->pos - c2->pos;
}

int numCows, freq [50000], curr = 0, present = 0, needed, s = 0, e = 0, ret = 1e9;
Cow cows [50000];
map<int, int> idToIndex;

int main(){
    freopen("lineup.in", "r", stdin); freopen("lineup.out", "w", stdout);
    scanf("%d", &numCows);
    for(int i = 0; i < numCows; i++){
        scanf("%d %d", &cows[i].pos, &cows[i].id);
        if(idToIndex.find(cows[i].id) == idToIndex.end()) idToIndex.insert(pair<int, int>(cows[i].id, curr++));
    }
    qsort(cows, numCows, sizeof(Cow), sorter);
    present++; needed = idToIndex.size(); freq[idToIndex.find(cows[0].id)->second]++;
    while(s <= e && e < numCows){
        if(present == needed){
            ret = min(ret, cows[e].pos-cows[s].pos);
            if(cows[e].pos-cows[s].pos == 1) cout << s << " " << e << endl;
            int ps = idToIndex.find(cows[s].id)->second;
            freq[ps]--; s++;
            if(freq[ps] == 0) present--;
        }
        else{
            e++; if(e == numCows) break;
            int pe = idToIndex.find(cows[e].id)->second;
            freq[pe]++; if(freq[pe] == 1) present++;
        }
    }
    cout << ret << endl;
    return 0;
}
