#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
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
#include <math.h>

using namespace std;

#define PI 3.141592653589793
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, M, si, sj, dist = 10000000;
pair<int, int> ret = make_pair(-1, -1);

int findDist(int ra, int ca, int rb, int cb){
    if(ra == rb && ca == cb) return 1;
    if(ra == rb) return abs(ca-cb)+1;
    if(ra > rb){ swap(ra, rb); swap(ca, cb); }
    if(ca%2 == 1) return min(findDist(ra, ca-1, rb, cb), findDist(ra, ca+1, rb, cb))+1;
    int cx = ca+1, cy = ca+(rb-ra)*2-1;
    if(cb <= cx) return (rb-ra)*2+(cx-cb);
    if(cb >= cy) return (rb-ra)*2+(cb-cy);
    if(cb%2 == 1) return (rb-ra)*2;
    return (rb-ra)*2+1;
}

int main(){
    //freopen("necklace.in", "r", stdin); freopen("necklace.out", "w", stdout);
    scanf("%d %d %d %d", &N, &M, &si, &sj); si--; sj--;
    for(int i = 0; i < M; i++){
        int r, c, temp; scanf("%d %d", &r, &c); r--; c--;
        temp = findDist(si, sj, r, c);
        if(temp < dist || (temp == dist && make_pair(r, c) < ret)){
            dist = temp;
            ret = make_pair(r, c);
	    }
    }
    cout << ret.first+1 << " " << ret.second+1 << '\n' << dist << '\n';
    return 0;
}
