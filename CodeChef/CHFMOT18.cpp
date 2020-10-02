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

int test_case(int s, int n)
{
	//int s, n; cin>>s>>n;
	if (s <= n) {
		if (s == n || s % 2 == 0 || s == 1)
			return 1;
		else
			return 2;
	}
	else {
		int ans;
		ans = s / n;
		if (s % n == 0)
			return ans;
		else {
			int k = s % n;
			ans = ans + test_case(k, n);
			return ans;
		}
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	fastio
	int t; cin >> t;
	while (t--) {
		int s, n; cin >> s >> n;
		cout << test_case(s, n) << "\n" ;
	}

	return 0;
}
