   #include <bits/stdc++.h>
   using namespace std;
   #define ll long long
   #define w(t) int t; cin>>t; while(t--)
   #define fo(i,n) for(int i=0;i<n;i++)
   #define endl "\n" 
   #define MOD 1000000007

   int main(){
      w(q){
         int n;
         cin>>n;
         int a[n];
         fo(i,n) cin>>a[i];
         string ans="NO";
         // Ans will be "YES" only if elements are in descending order as min no. of swaps needed to sort it in 
         // ascending order will be n*(n-1)/2,else ans will be "NO". 
         for(int i=1;i<n;i++){  //Checking whether elements are in descending order or not
            if(a[i-1]<=a[i]){
               ans="YES";
               break;
            }
         }
         cout<<ans<<endl;
      }
      return 0;
   }

