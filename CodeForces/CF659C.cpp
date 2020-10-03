#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fin for(int i=0;i<n;i++)
#define ff first
#define ss second
#define vi vector<int>
#define vc vector<char>
#define vii vector<int,int>
#define pb push_back
#define mp make_pair
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
    while(t--){
    int a[20],b[20];
    for(int i=0;i<20;i++){
    	a[i]=0;
    	b[i]=0;
    }
    int n;
    cin>>n;
    vc ai,bi;
   	string s,x;
   	cin>>s>>x;
   	sort(s,s+n);
   	sort(x,x+n);
   	int i=0;j=0;
   	while(i<n && j<n){
   		if(s[i]==x[j]){
   			i++;
   			j++;
   		}
   		else
   		{
   			ai.pb(s[i]);
   			bi.pb(x[i]);
   			i++;
   			j++;
   		}
    }
    while(i<n){
    	ai.pb(s[i]);
    	i++;
    }
    while(j<n){
    	bi.pb(x[j]);
    	j++;
    }
    int count=0,flag=0;
    for(int i=0;i<ai.size();i++)
    {
    	if(ai[i]>bi[i]){
    		cout<<-1<<endl;
    		flag=1;
    		break;
    	}
    	else{
    		count++;
    	}
    }
    if(flag==0)
    	cout<<count<<endl;
}
    return 0;
}