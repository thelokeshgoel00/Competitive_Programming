   #include <bits/stdc++.h>
   using namespace std;
   #define ll long long
   #define w(t) int t; cin>>t; while(t--)
   #define fo(i,n) for(int i=0;i<n;i++)
   #define endl "\n" 
   #define MOD 1000000007

   // this method will return pos of right most 1-bit
   int getRtMostOnBit(ll x){ 
      return (int)log2(x)+1;
   }
   int main(){
      
      //   a&b>=a^b only when pos of right most 1-bit is same in both
      w(q){
         ll n,ans=0;
         cin>>n;
         ll a[n];
         fo(i,n) cin>>a[i];
         vector<int>rtMostOnBit(n); // this stores the pos of right most 1-bit of each no.
         fo(i,n){
            rtMostOnBit[i]=getRtMostOnBit(a[i]);
         }
         sort(rtMostOnBit.begin(),rtMostOnBit.end());
         for(int i=1;i<n;i++){  
            ll c=1;
            // this checks the no. of elements having same pos of right most 1-bit 
            while(i<n && rtMostOnBit[i]==rtMostOnBit[i-1]){
               c++;
               i++;
            }
            ans+=(c*(c-1)/2); // as there can be c*(c-1)/2 pairs,if there are c nos having same pos of right most 1-bit
         }
         cout<<ans<<endl;
      }
      return 0;
   }

