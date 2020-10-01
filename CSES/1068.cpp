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
#define pii pair<int,int>
#define vp vector<pair<int,int > >
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define gsz(x) ((int)(x).size())
#define F first
#define S second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cerr.tie(NULL);
#define endl "\n"
#define ms(x,v) memset(x,v,sizeof(x))
 
int main()
{
	fastio;
	ll n;
	cin>>n;
	cout<<n<<" ";
	while(n>1){
		if(n%2==0){
			n/=2;
		}
		else{
			n = 3*n+1;
		}
		cout<<n<<" ";
	}
 
 
	return 0;
}
