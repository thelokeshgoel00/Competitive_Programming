/******************************************
* AUTHOR : PRIYAM THAKURIA*
* NICK : pziphon_hack *
* INSTITUTION : NIT Kurukshetra *
******************************************/
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define REP(i,a,b) for (int i = a; i < b; i++)
#define rep(i,a,b) for (int i = a; i >= b; i--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {

	fastio
	ll t; cin >> t;
	while (t--) {
		ll s = 0, c = 0, n, x;
		cin >> n >> x;
		vector<ll> v;
		ll n1 = n;
		for (ll i = 0; i < n; i++) {
			int k; cin >> k;
			v.push_back(k);
		}
		sort(v.begin(), v.end());
		while (!v.empty()) {
			auto up = upper_bound(v.begin(), v.end(), x);
			if (up == v.begin()) {
				x *= 2;
			}
			else {
				auto i = up;
				up--;
				ll prev = v[up - v.begin()];
				if (i == v.end() || x <= (2 * prev)) {
					x = 2 * prev;
					v.erase(up);
				}
				else {
					x *= 2;
				}
			}
			s++;
		}
		cout << s << "\n";
	}
	return 0;
}
