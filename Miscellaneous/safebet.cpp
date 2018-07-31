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

using namespace std;

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

struct Segment{
    int a, b, c, d;
    Segment(){ a = b = c = d = 0; }
    Segment(int aa, int bb, int cc, int dd){
        a = aa; b = bb; c = cc; d = dd;
        if(mp(a, b) > mp(c, d)){
            swap(a, c);
            swap(b, d);
        }
        if(a == c){ b++; d--; }
        else{ a++; c--; }
    }
    bool operator<(const Segment &other) const{ return a < other.a; }
};

int kase = 0, R, C, M, N, tree [1000010];
unordered_map<int, set<int>> rowMirrors, colMirrors;
unordered_map<long long, int> mirrorType;
vector<vector<Segment>> sourcePath, destPath; // 0 = horizontal and 1 = vertical
long long ret;
pair<int, int> lastSeen, pos;

void add(int pos, int x){
    while(pos < 1000010){
        tree[pos] += x;
        pos += (pos&-pos);
    }
}

long long query(int pos){
    long long sum = 0;
    while(pos > 0){
        sum += tree[pos];
        pos -= (pos&-pos);
    }
    return sum;
}

long long query(int li, int ri){ return query(ri)-query(li-1); }

long long hashy(long long r, long long c){ return MOD*r+c; }

vector<vector<Segment>> generatePath(int r, int c, int dir){
    vector<vector<Segment>> pathy(2); int nr, nc;
    do{
        // right, down, left, up
        if(dir == 0){
            auto it = rowMirrors[r].upper_bound(c);
            nr = r; nc = it == rowMirrors[r].end() ? C+1 : *it;
            if(abs(nc-c) > 1 || abs(nr-r) > 1) pathy[0].pb(Segment(r, c, nr, nc));
            if(mirrorType[hashy(nr, nc)] == 0) dir = 3;
            else dir = 1;
        }
        else if(dir == 1){
            auto it = colMirrors[c].upper_bound(r);
            nr = it == colMirrors[c].end() ? R+1 : *it; nc = c;
            if(abs(nc-c) > 1 || abs(nr-r) > 1) pathy[1].pb(Segment(r, c, nr, nc));
            if(mirrorType[hashy(nr, nc)] == 0) dir = 2;
            else dir = 0;
        }
        else if(dir == 2){
            if(rowMirrors[r].size() == 0){ nr = r; nc = 0; }
            else{
                auto it = rowMirrors[r].lower_bound(c); if(it != rowMirrors[r].begin()) it--;
                nr = r; nc = *it < c ? *it : 0;
            }
            if(abs(nc-c) > 1 || abs(nr-r) > 1) pathy[0].pb(Segment(r, c, nr, nc));
            if(mirrorType[hashy(nr, nc)] == 0) dir = 1;
            else dir = 3;
        }
        else{
            if(colMirrors[c].size() == 0){ nr = 0; nc = c; }
            else{
                auto it = colMirrors[c].lower_bound(r); if(it != colMirrors[c].begin()) it--;
                nr = *it < r ? *it : 0; nc = c;
            }
            if(abs(nc-c) > 1 || abs(nr-r) > 1) pathy[1].pb(Segment(r, c, nr, nc));
            if(mirrorType[hashy(nr, nc)] == 0) dir = 0;
            else dir = 2;
        }
        //cout << r << ' ' << c << ' ' << nr << ' ' << nc << endl;
        r = nr; c = nc; lastSeen = mp(r, c);
    }while(r >= 1 && c >= 1 && r <= R && c <= C);
    return pathy;
}

long long sweep(vector<Segment> horizontal, vector<Segment> vertical){
    long long cnt = 0; fill(tree, tree+1000010, 0);
    vector<pair<pair<int, int>, int>> events;
    for(Segment s : vertical){
        events.pb(mp(mp(s.a, -1), s.b)); // Add
        events.pb(mp(mp(s.c, 1), s.b)); // Remove
    }
    sort(events.begin(), events.end()); sort(horizontal.begin(), horizontal.end());
    pair<int, int> lexi = mp(MOD, MOD);
    int hindex = 0, eindex = 0;
    while(hindex < horizontal.size()){
        int r = horizontal[hindex].a;
        while(eindex < events.size() && events[eindex].f < mp(r, 1)){
            add(events[eindex].s, -events[eindex].f.s);
            eindex++;
        }
        pair<int, int> searchy = mp(MOD, MOD);
        while(hindex < horizontal.size() && horizontal[hindex].a == r){
            long long add = query(horizontal[hindex].b, horizontal[hindex].d);
            if(add > 0) searchy = min(searchy, mp(horizontal[hindex].b, horizontal[hindex].d));
            cnt += add; hindex++;
        }
        if(lexi.f == MOD && searchy.f != MOD){
            int lv = searchy.f, rv = searchy.s, mini;
            while(lv <= rv) {
                int mid = (lv+rv)/2;
                long long num = query(searchy.f, mid);
                if(num > 0){ rv = mid-1; mini = mid; }
                else lv = mid+1;
            }
            lexi = mp(r, mini);
        }
    }
    pos = min(pos, lexi);
    return cnt;
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(2);
    while(cin >> R >> C >> M >> N){
        rowMirrors.clear(); colMirrors.clear(); mirrorType.clear();
        ret = 0; pos = mp(MOD, MOD); kase++;
        rowMirrors[R] = set<int>(); colMirrors[C] = set<int>();
        for(int i = 0; i < M; i++){
            int a, b; cin >> a >> b;
            if(rowMirrors.find(a) == rowMirrors.end()) rowMirrors[a] = set<int>();
            if(colMirrors.find(b) == colMirrors.end()) colMirrors[b] = set<int>();
            rowMirrors[a].insert(b); colMirrors[b].insert(a);
            mirrorType[hashy(a, b)] = 0;
        }
        for(int i = 0; i < N; i++){
            int a, b; cin >> a >> b;
            if(rowMirrors.find(a) == rowMirrors.end()) rowMirrors[a] = set<int>();
            if(colMirrors.find(b) == colMirrors.end()) colMirrors[b] = set<int>();
            rowMirrors[a].insert(b); colMirrors[b].insert(a);
            mirrorType[hashy(a, b)] = 1;
        }
        sourcePath = generatePath(1, 0, 0);
        if(lastSeen == mp(R, C+1)){
            cout << "Case " << kase << ": 0\n";
            continue;
        }
        else destPath = generatePath(R, C+1, 2);
        ret = sweep(sourcePath[0], destPath[1])+sweep(destPath[0], sourcePath[1]);
        if(ret == 0) cout << "Case " << kase << ": impossible\n";
        else cout << "Case " << kase << ": " << ret << ' ' << pos.f << ' ' << pos.s << '\n';
    }
    return 0;
}
