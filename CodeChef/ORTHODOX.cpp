#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fin for(int i=0;i<n;i++)
#define ff first
#define ss second
#define vi vector<int>
#define vc vector<char>
#define vii vector<int,int>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
 	int t;
 	cin>>t;
 	ll a[100005];
 	while(t--){
 		int n,flag=0,j;
 		set<int> se;
 		cin>>n;
 		fin{
 			cin>>a[i];
 		}
 		for(int i=0;i<n;i++)
 		{
 			int ans=0;
 			j=i;
 			while(j<n)
 			{
 				ans=ans|a[j];
 				if(se.find(ans)==se.end())
 				se.insert(ans);
 				else{
 					flag=1;
 					break;
 				}
 				j++;
 			}
 		}
 		if(flag==1)
 			cout<<"NO"<<endl;
 		else
 			cout<<"YES"<<endl;
 	}   
    return 0;
}