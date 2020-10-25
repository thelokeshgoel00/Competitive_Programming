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
         vector<string>v(n);
         fo(i,n){
            cin>>v[i];
         }
         int f[26]={0};
         // Here we are finding the frequency of each charachter
         fo(i,n){
            for(int j=0;j<v[i].length();j++){  
                 f[v[i][j]-97]++;
            }
         }
         int flag=1;
         fo(i,26){
            if(f[i]%n!=0){ // if any freq of any ch is not divisible by n,then ans will be NO.
               cout<<"NO\n";
               flag=0;
               break;
            }
         }
         if(flag){
             cout<<"YES\n";
         }
      }
      return 0;
   }

