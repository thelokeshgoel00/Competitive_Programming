/*
Solution
    - Every number from A' can be represented as S = (another number from A') + k * a[i]
    - The above relation holds when both sides are taken modulo a[0]
    - We perform a modified Dijkstra's
    - The "distance" to node 0 <= R < a[0] is the smallest value of S/a[0] at which the residue R can be reached
    - Queries are answered in O(1) by checking if the number X satisfies dist[X%a[0]] <= X/a[0]
*/

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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
template <class T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

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

int N, M, arr [5010], visited [50010];
queue<int> q;

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
	cin >> N; fill(visited, visited+50010, MOD);
	for(int i = 0; i < N; i++) cin >> arr[i];
	visited[0] = 0; q.push(0);
	while(q.size() > 0){
		int now = q.front(); q.pop();
		if(now > MOD) continue;
		for(int i = 1; i < N; i++)
			if((now+arr[i])/arr[0] < visited[(now+arr[i])%arr[0]]){
				visited[(now+arr[i])%arr[0]] = (now+arr[i])/arr[0];
				q.push((now+arr[i]));
			}
	}
	cin >> M;
	for(int i = 0; i < M; i++){
		int x; cin >> x;
		cout << (visited[x%arr[0]] <= x/arr[0] ? "TAK" : "NIE") << '\n';
	}
	return 0;
}

/******************************
Kateba ii dake no hanashi darou
Success is only a victory away
- No Game No Life Opening
******************************/
