   #include <bits/stdc++.h>
   using namespace std;
   #define ll long long
   #define w(t) int t; cin>>t; while(t--)
   #define fo(i,n) for(int i=0;i<n;i++)
   #define endl "\n" 
   #define MOD 1000000007

   int main(){
      // the player who got first pile of stones having (no. of stones> 1) will win.
	  w(q){
		  int n;
		  cin>>n;
		  int a[n];
		  fo(i,n) cin>>a[i];
		  int ind=-1; // it stores the index of first pile of stones having (no. of stones> 1).
		  fo(i,n-1){
			  if(a[i]>1){
				  ind=i+1;
				  break;
			  }
		  }
          // Edge Case- if all piles have 1 stone.
          // if n is odd,then player who make first move will win,else second will win.
		  if(ind==-1){  
			  if(n&1) cout<<"First\n";
			  else cout<<"Second\n";
			  continue;
		  }
         // if ind is odd,then the player who makes first move will reach that pile(no. of stones> 1),else second. 
		  if(ind&1) cout<<"First\n";
		  else cout<<"Second\n";
	  }
	  return 0;
   }

