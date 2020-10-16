#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;cin>>n;
	vector<int> m,f;
	while(n--){
		int x;cin>>x;
		if(x==0){
			int p;cin>>p;
			f.push_back(p);
		}else{
			int p;cin>>p;
			m.push_back(p);
		}
	}
	sort(m.begin(),m.end(),greater<int>());
  sort(f.begin(),f.end(),greater<int>());

	for(int i=0;i<f.size();i++){
    cout<<f[i]<<" ";
  }
  
	for(int i=0;i<m.size();i++){
    cout<<m[i]<<" ";
  }
}