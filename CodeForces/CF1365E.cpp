#include<bits/stdc++.h>
using namespace std;
#define ll int long long
#define mp make_pair
//#define for(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define N 1000000007
#define pq priority queue
#define pb push_back
#define pf push_front
#define mt make_tuple
#define prec(a) fixed<<setprecision(9)<<a
#define endl "\n"
#define fast_set s.max_load_factor(0.25);s.reserve(500);
#define cy cout<<"YES"<<endl;
#define cn cout<<"NO"<<endl;
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
const long double PI = (long double)(3.1415926535897932384626433832795);

int main() 
{
	fast;
	ll n,i,j,k;
	cin>>n;
	ll a[n];
	ll maxi=0,count=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i]; // taking input array elements.
		
	}
	ll ans = 0;
 
  	for (int i = 0; i < n; i++) {
    	ans = max(ans, a[i]); // if taking single element as answer
    	for (int j = i + 1; j < n; j++) {
      		ans = max(ans, a[i] | a[j]); // if taking bitwise OR of two.
      		for (int k = j + 1; k < n; k++) {
        		ans = max(ans, a[i] | a[j] | a[k]); // if taking bitwise OR of three.
      		}
    	}
  	}
  
  	cout << ans << endl;
	
	return 0;
}