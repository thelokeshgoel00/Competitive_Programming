#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string.h>
#include <math.h>

using namespace std;

#define PI 3.141592653589793
#define epsilon 0.000000001
#define INF 1000000000000000000
#define MOD 1000000007

int N, original [100010], desired [100010], moves [100010];
long long ret = 0ll;

int main(){
    freopen("restack.in", "r", stdin); freopen("restack.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d %d", &original[i], &desired[i]);
    moves[0] = original[0]-desired[0];
    for(int i = 1; i < N; i++) moves[i] = moves[i-1]+original[i]-desired[i];
    sort(moves, moves+N);
    for(int i = 0; i < N; i++) ret += abs(moves[i]-moves[N/2]);
    cout << ret << '\n';
    return 0;
}

/*
Source: https://github.com/koosaga/olympiad/blob/master/USACO/mar12_restack.cpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, a[100005], b[100005];

lint trial(int p){
	lint ret = 0;
	int sa = 0, sb = 0;
	for(int i=0; i<n; i++){
		sa += a[i];
		sb += b[i];
		ret += abs(sa - p - sb);
	}
	return ret;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i] >> b[i];
	}
	lint ret = 1e18;
	int s = -1e9, e = 1e9;
	while(s != e){
		int m = s + e;
		if(m < 0) m = (m-1) / 2;
		else m = m/2;
		if(trial(m) < trial(m+1)) e = m;
		else s = m+1;
	}
	cout << trial(s);
}
*/
