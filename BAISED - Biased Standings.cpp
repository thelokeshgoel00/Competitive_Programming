#include<bits/stdc++.h>
using namespace std;
#define ss(n) scanf("%d", &n)
#define pp(n) printf("%lld\n",n)
#define ab(a,b) a>b? a-b:b-a
bool cmp(pair<string,int> a, pair<string,int> b){
	return a.second<b.second;
}
int main(){
	int test;
	ss(test);
	while(test--){
		int n;
		ss(n);
		string s;
		int r;
		std::vector<pair<string, int> > v;
		for(int i=0; i<n; i++){
			cin>>s;
			ss(r);
			v.push_back(make_pair(s,r));
		}
		sort(v.begin(), v.end(), cmp);
		ll sum=0;
		for(int i=0;i<n; i++){
			sum+=  ab(i+1, v[i].second);
		}
		pp(sum);
	}
}