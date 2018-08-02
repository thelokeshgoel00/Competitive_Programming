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

int B, N, D, M, arr1D [100010], tree [150010], tree3D [250][250][250];
pair<int, int> arr2D [100010];
pair<pair<int, int>, pair<int, int>> arr4D [100010];
long long ret = 0;

void solve1D(){
    for(int i = 0; i < N; i++) cin >> arr1D[i];
    sort(arr1D, arr1D+N);
    for(int i = 0, j = 0; i < N; i++){
        while(j < i && arr1D[j]+D < arr1D[i]) j++;
        ret += (long long)(i-j);
    }
}

void add(int pos, int x){
    while(pos <= 2*M){
        tree[pos] += x;
        pos += (pos&-pos);
    }
}

long long query(int pos){
    long long sum = 0ll;
    while(pos > 0){
        sum += tree[pos];
        pos -= (pos&-pos);
    }
    return sum;
}

void solve2D(){
    for(int i = 0; i < N; i++){
        int a, b; cin >> a >> b;
        arr2D[i].f = a+b; arr2D[i].s = a-b+M;
    }
    sort(arr2D, arr2D+N);
    for(int i = 0, j = 0; i < N; i++){
        while(j < i && arr2D[j].f+D < arr2D[i].f){
            add(arr2D[j].s, -1);
            j++;
        }
        ret += query(min(arr2D[i].s+D, 2*M))-query(max(arr2D[i].s-D, 1)-1);
        add(arr2D[i].s, 1);
    }
}

void add(int a, int b, int c, int x){
    for(int i = a; i <= 3*M; i += (i&-i))
        for(int j = b; j <= 3*M; j += (j&-j))
            for(int k = c; k <= 3*M; k += (k&-k))
                tree3D[i][j][k] += x;
}

long long query(int a, int b, int c){
    long long ret = 0;
    for(int i = a; i > 0; i -= (i&-i))
        for(int j = b; j > 0; j -= (j&-j))
            for(int k = c; k > 0; k -= (k&-k))
                ret += tree3D[i][j][k];
    return ret;
}

long long query(int a, int b, int c, int d, int e, int f){
    return query(d, e, f)-query(a-1, e, f)-query(d, b-1, f)-query(d, e, c-1)+
            query(a-1, b-1, f)+query(a-1, e, c-1)+query(d, b-1, c-1)-query(a-1, b-1, c-1);
}

void solve3D(){
    for(int i = 0; i < N; i++){
        int a, b, c; cin >> a >> b >> c;
        arr4D[i].f.f = a+b+c; arr4D[i].f.s = a+b-c+M;
        arr4D[i].s.f = a-b+c+M; arr4D[i].s.s = a-b-c+2*M;
    }
    sort(arr4D, arr4D+N);
    for(int i = 0, j = 0; i < N; i++){
        while(j < i && arr4D[j].f.f+D < arr4D[i].f.f){
            add(arr4D[j].f.s, arr4D[j].s.f, arr4D[j].s.s, -1);
            j++;
        }
        ret += query(max(arr4D[i].f.s-D, 1), max(arr4D[i].s.f-D, 1), max(arr4D[i].s.s-D, 1),
                     min(arr4D[i].f.s+D, 3*M), min(arr4D[i].s.f+D, 3*M), min(arr4D[i].s.s+D, 3*M));
        add(arr4D[i].f.s, arr4D[i].s.f, arr4D[i].s.s, 1);
    }
}

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(2);
    cin >> B >> N >> D >> M;
    if(B == 1) solve1D();
    else if(B == 2) solve2D();
    else solve3D();
    cout << ret << '\n';
    return 0;
}
