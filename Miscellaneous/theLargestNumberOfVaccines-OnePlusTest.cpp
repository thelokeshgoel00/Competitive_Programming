/******************************************
* AUTHOR : Lokesh goel*
* NICK : InsaneNerd *
* INSTITUTION : NIT Kurukshetra *
******************************************/
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000000000
#define N 100005
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cerr.tie(NULL);
#define endl "\n"
#define ms(x,v) memset(x,v,sizeof(x))

void solve(){
	ll k;
	cin>>k;
	ll a[9],i,j;
	ll mini = INT_MAX;
	ll minval;
	for(i=0;i<9;i++){
		cin>>a[i];
		if(mini>=a[i]){
			mini = a[i];
			minval = i+1;
		}
	}

	int digits = k/mini;
	if(digits==0){
		cout<<"-1"<<endl;
		return;
	}
	vector<int>v(digits,minval);
	int left = k%mini;
	for(i=0;i<digits;i++){
		for(j = 9;j>minval;j--){
			if(left-a[j-1]+mini>=0){
				left -= (a[j-1]-mini);
				v[i]=j;
				break;
			}
		}
	}
	for(auto it:v){
		cout<<it;
	}
	cout<<endl;
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		solve();
	}


	return 0;
}