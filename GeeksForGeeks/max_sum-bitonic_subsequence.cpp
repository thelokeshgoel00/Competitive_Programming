#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int ar[n];
	    for(int i=0; i<n; i++){
	        cin>>ar[i];
	    }
	    vector<int> vi(n,0),vd(n,0);
	    for(int i=0; i<n; i++){
	       // vi[i].push_back(ar[i]);
	       vi[i]+=ar[i];
	        for(int j=0; j<i; j++){
	            if(ar[j]<ar[i]){
	                if(ar[i]+vi[j]>vi[i]){
	                    vi[i]=vi[j]+ar[i];
	                }
	            }
	        }
	    }
	    for(int i=n-1; i>=0; i--){
	       // vi[i].push_back(ar[i]);
	       vd[i]+=ar[i];
	        for(int j=n-1; j>i; j--){
	            if(ar[j]<ar[i]){
	                if(ar[i]+vd[j]>vd[i]){
	                   vd[i]=vd[j]+ar[i];
	                }
	            }
	        }
	    }
	    int mm=0,idx=0;
	    for(int i=0; i<n; i++){
	       // cout<<vi[i]<<" "<<vd[i]<<endl;
	        if(vi[i]+vd[i]-ar[i]>mm){
	            mm=vi[i]+vd[i]-ar[i];
	           // idx=i;
	        }
	       // mm=max(mm,vi[i]+vd[i]);
	    }
	    cout<<mm<<endl;
	}
	return 0;
}