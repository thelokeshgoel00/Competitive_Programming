// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int recur(string s1,string s2, int l1, int l2){
        if(l1==0&&l2==0 || l2==0){
            return 1;
        }
        if(l1==0){
            return 0;
        }
        if(s1[l1-1]==s2[l2-1]){
            return recur(s1,s2,l1-1,l2-1)+recur(s1,s2,l1-1,l2);
        }
        else{
            return recur(s1,s2,l1-1,l2);
        }
    }
    int countWays(string S1, string S2){
        // code here
        return recur(S1,S2,S1.size(),S2.size());
        // int dp[][]
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}  // } Driver Code Endss