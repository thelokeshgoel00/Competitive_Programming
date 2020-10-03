#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	ll t,n;
	cin>>t;
	while(t--){
		cin>>n;
		ll sumf,count,sumn,i,half,diff;
		sumf=(n*(n+1))/2;
		count=0;
		if(sumf%2==0){
			half=sumf/2;
			i=sqrt(sumf);
			sumn=(i*(i+1))/2;
			if(sumn>half)
				sumn-=i,i--;
			diff=half-sumn;
			while(diff<n && diff>=0){
				if(diff==0){
					count+=(i*(i-1))/2;
					ll m=n-i;
					count+=(m*(m-1))/2;
				}
				else if(diff<n){
					if(diff+1>i)
    	                count+=min(n-diff,i);
    	            else
    	        		count+=min(n-i,diff);
				}
				diff+=i;i--;
			}
			cout<<count<<endl;
		}
		else
			cout<<0<<endl;
	}
	return 0;
}
