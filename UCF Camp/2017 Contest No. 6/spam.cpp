#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string.h>
#include <math.h>

using namespace std;

int n, curId = 0;
bool marked [100];
map<string, int> messageFreq [100];
map<string, int> nameToId;
map<int, string> idToName;
vector<string> ret;
string s;

int main(){
    cin >> n; getline(cin, s); memset(marked, false, sizeof(marked));
    for(int i = 0; i < n; i++){
        string namo, mess; getline(cin, s);
        namo = s.substr(0, s.find(":"));
        mess = s.substr(s.find(":")+2);
        //cout << namo << " " << mess;
        if(nameToId.find(namo) == nameToId.end()){
            nameToId[namo] = curId;
            idToName[curId] = namo;
            curId++;
        }
        int id = nameToId[namo];
        if(messageFreq[id].find(mess) == messageFreq[id].end()) messageFreq[id][mess] = 0;
        messageFreq[id][mess]++;
        if(messageFreq[id][mess] == 3 && !marked[id]){ ret.push_back(namo); marked[id] = true; }
    }
    sort(ret.begin(), ret.end());
    if(ret.size() == 0) cout << "-1\n";
    else{ for(int i = 0; i < ret.size(); i++) cout << ret[i] << '\n'; }
    return 0;
}
