#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fin for(int i=0;i<n;i++)
#define ff first
#define ss second
#define vi vector<int>
#define vc vector<char>
#define vii vector<int,int>
int factorial(int n) 
{ 
    // single line to find factorial 
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1); 
} 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	ll sum=0;
    	fin{
    		int val;
    		cin>>val;
    		sum+=val;
       	}
       	sum*=factorial(n-1);
       	ll ans=((pow(10,n)-1)/9)*sum;
       	cout<<ans<<endl;
    }
    return 0;
}