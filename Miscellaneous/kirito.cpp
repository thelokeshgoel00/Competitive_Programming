#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int N, M, Q;
int tree [8001], mp [2001];
vector<long long> hashes [2001];

int left(int p){ return p<<1; }
int right(int p){ return (p<<1)+1; }

void hashIt(string s, int a){
    int h = 1;
    for(int i = 0; i < s.length(); i++){
        h = h*43; if(s[i] == '1') h++;
        hashes[a].push_back(h);
    }
}

int findLow(int a, int b, int lo, int hi){
    int ans = -1;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(hashes[a][mid] == hashes[b][mid]){
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    return ans;
}

void build(int p, int L, int R){
    if(L == R){
        tree[p] = M-1;
        return;
    }
    int li = left(p); int ri = right(p);
    build(li, L, (L+R)/2); build(ri, (L+R)/2+1, R);
    tree[p] = findLow(mp[L], mp[R], 0, min(tree[li], tree[ri]));
}

void update(int p, int L, int R, int place){
    if(L > R || L > place || R < place) return;
    if(L == R) return;
    int li = left(p); int ri = right(p);
    update(li, L, (L+R)/2, place); update(ri, (L+R)/2+1, R, place);
    tree[p] = findLow(mp[L], mp[R], 0, min(tree[li], tree[ri]));
}

int query(int p, int L, int R, int i, int j){
    if(i > R || j < L) return -2;
    if(i <= L && j >= R) return tree[p];
    int li = left(p); int ri = right(p);
    int a1 = query(li, L, (L+R)/2, i, j);
    int a2 = query(ri, (L+R)/2+1, R, i, j);
    if(a1 == -2) return a2;
    if(a2 == -2) return a1;
    return findLow(mp[max(L, i)], mp[min(R, j)], 0, min(a1, a2));
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        string temp; cin >> temp; mp[i] = i;
        hashIt(temp, i);
    }
    build(1, 0, N-1); scanf("%d", &Q);
    for(int i = 0; i < Q; i++){
        int a, b; scanf("%d %d", &a, &b);
        cout << (query(1, 0, N-1, a-1, b-1)+1)*(b-a+1) << endl;
        swap(mp[a-1], mp[b-1]);
        update(1, 0, N-1, a-1); update(1, 0, N-1, b-1);
    }
    return 0;
}
