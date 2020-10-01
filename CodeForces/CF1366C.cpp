#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define fi first
#define s second
#define mem(x, vertexal) memset(x, vertexal, sizeof(x))
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define endl "\n"
#define mp make_pair
#define print_arr(a,n) for(long long int i = 0; i < n; i++) cout << a[i] << " ";
#define print_vertexec(vertex) for(long long int i = 0; i < vertex.size(); i++) cout << vertex[i] << " ";
#define f(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define cy cout<<"YES"<<endl;
#define cn cout<<"NO"<<endl;
using namespace std;
int main()
{
	fast;
	//code here
	ll t;
	cin>>t;
	while(t--){
			// output 
			ll n,m;
			cin>>n>>m;
			ll a[n+1][m+1];
			// array a,b
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					cin>>a[i][j];
				}
			}
			// map< ll ,ll>ma1,ma2;

			// for(ll i=1;i<=n;i++)
			// {
			// 	for(ll j=1;j<=m;j++)
			// 	{
			// 		ma1[i+j]=0;
			// 		ma2[i+j]=0;
			// 	}
			// }
			

			ll store[n+m+2][2];
			mem(store,0);
			for(ll i=0;i<n;i++){
				for(ll j=0;j<m;j++){
					store[i+j][a[i][j]]+=1;
				}
			}
			// start=0
			// end
			ll start=0;
			ll end=m+n-2;
			ll ans=0;
			for(ll i=0;i<end;i++,end--){
				ans+=min(store[i][0]+store[end][0],store[i][1]+store[end][1]);	
			}
			//ouput 
			cout<<ans<<endl;
			// for(ll i=1;i<=n;i++)
			// {
			// 	for(ll j=1;j<m;j++)
			// 	{
			// 		if(a[i][j]==1)
			// 		{

			// 			// v1[i+j]s+=1;
			// 			ma1[i+j]+=1;
			// 		}
			// 		else
			// 		{
			// 			// v1[i+j].fi+=1;
			// 			ma2[i+j]+=1;			
			// 		}
			// 	}
			// }
			// vector< ll > v1,v2 ;
			// map< ll ,pair< ll ,ll > >ma;
			// for(auto it:ma1)
			// {
			// 	if(ma1.find(m+n+2-it.fi)!=ma1.end())
			// 	{
			// 		ma1[m+n+2-it.fi]+=ma1[it.fi];
			// 		v1.pb(ma1[m+n+2-it.fi]);
			// 		ma1[it.fi]=0;
			// 	}
			// 	else if(it.fi==(m+n+2)/2)
			// 	{
			// 		v1.pb(ma1[(m+n+2)/2]);
			// 	}
			// }
			// for(auto it:ma2)
			// {
			// 	if(ma2.find(m+n+2-it.fi)!=ma2.end())
			// 	{
			// 		ma2[m+n+2-it.fi]+=ma2[it.fi];
			// 		v2.pb(ma2[m+n+2-it.fi]);
			// 		ma2[it.fi]=0;
			// 	}
			// 	else  if(it.fi==(m+n+2)/2)
			// 	{
			// 		v2.pb(ma2[(m+n+2)/2]);
			// 	}
			// }
			// ll c=0;
			// for(int i=0;i<v1.size();i++){
			// 	c+=min(v1[i],v2[i]);
			// }
			// cout<<c<<endl;
			
			
			


			



	}
	return 0;

}

