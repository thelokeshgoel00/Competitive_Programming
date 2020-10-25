#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n;
	int v[5+1];
	int in[5+1];
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i];
		}
		for(int i=1;i<=n;i++){
			int count=1;
			if(v[i]!=0){
				for(int j=1;j<=n;j++){
					if(i!=j&&(v[i]-v[j])!=0){
						float x=j-i;
						float y=v[i]-v[j];
						float m=x/(float)y;
						if(m>=0)
							count++;
					}
				}
			}
			in[i]=count;
		}
		sort(in+1,in+n+1);
		cout<<in[1]<<" "<<in[2]<<endl;
	}
	return 0;
}
