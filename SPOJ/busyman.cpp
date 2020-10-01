#include<bits/stdc++.h>
using namespace std;
#define ss(n) scanf("%d", &n)
#define pp(n) printf("%d\n",n)
bool cmp(pair<int,int> a, pair<int,int> b){
	return a.second<b.second;
}
int main(){
	int test;
	ss(test);
	while(test--){
		int n,s,e;
		ss(n);
		std::vector<pair<int,int> > v;
		for(int i=0; i<n; i++){
			ss(s);
			ss(e);
			v.push_back(make_pair(s,e));
		}
		sort(v.begin(), v.end(), cmp);
		int work=1;
		int finish_time=v[0].second;
		for(int i=1; i<n; i++){
			if(v[i].first>=finish_time){
				finish_time=v[i].second;
				work++;
			}
		}
		pp(work);
	}
}
