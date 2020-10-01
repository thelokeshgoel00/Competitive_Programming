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
//#define endl "\n"
#define fast_set s.max_load_factor(0.25);s.reserve(500);
#define cy cout<<"YES"<<endl;
#define cn cout<<"NO"<<endl;
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
const long double PI = (long double)(3.1415926535897932384626433832795);


// Interactive Problem
int main() 
{
	fast;
	int n,i,j;
	cin>>n;
	set<int>s;
	// inserting 1 to n into set.
	for(i=1;i<=n;i++)
	{
		s.insert(i);
	}
	int arr[n]={0};

	// we have atmost 2n queries but this logic solving the problem in 2(n-1) queries.
	for(i=1;i<=n-1;i++)
	{
		// extracting the first two minimum elements from set.
		auto it1=s.begin(); 
		auto it2=it1;
		it2++;
		int a,b;
		cout<<"? "<<(*it1)<<" "<<(*it2)<<endl;
		cin>>a;
		cout<<"? "<<(*it2)<<" "<<(*it1)<<endl;
		cin>>b;
		if(a<b)
		{
			arr[(*it2)-1]=b;
			s.erase((*it2));
		}
		else
		{
			arr[(*it1)-1]=a;
			s.erase((*it1));
		}
	}
	arr[(*s.begin())-1]=n;

	// output the result.
	cout<<"! ";
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}







 