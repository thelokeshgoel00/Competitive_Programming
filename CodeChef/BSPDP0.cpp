/******************************************
* AUTHOR : Lokesh goel*
* NICK : InsaneNerd *
* INSTITUTION : NIT Kurukshetra *
******************************************/
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000000000
#define N 100005
#define pii pair<int,int>
#define vp vector<pair<int,int > >
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define gsz(x) ((int)(x).size())
#define F first
#define S second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cerr.tie(NULL);
#define endl "\n"
#define ms(x,v) memset(x,v,sizeof(x))

set<int>  SieveOfEratosthenes(int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    set<int> res;
    ll last=0;
    // Print all prime numbers 
    for (int p=2; p<=n; p++){
       if (prime[p]){
        res.insert(p);
       }
   }
   return res;
           
} 

void printSubsequences(vector<int> arr, int index,  
                       vector<int> subarr,vector<vector<int>>&subsequence) 
{ 
    // Print the subsequence when reach 
    // the leaf of recursion tree 
    if (index == arr.size()) 
    { 
        int l = subarr.size(); 
  
        // Condition to avoid printing 
        // empty subsequence 
        if (l != 0) 
            subsequence.push_back(subarr);
            
    } 
    else
    { 
        // Subsequence without including 
        // the element at current index 
        printSubsequences(arr, index + 1, subarr,subsequence); 
  
        subarr.push_back(arr[index]); 
  
        // Subsequence including the element 
        // at current index 
        printSubsequences(arr, index + 1, subarr,subsequence); 
    } 
    return; 
} 

int main()
{
    fastio;
    ll n,m,i,j,k;
    vector<vector<int>>v;
    map<int,int>m1;
    set<int>primes = {2,3,5,7,11,13,17,19};
    vector<int>prime = {2,3,5,7,11,13,17,19};
    cin>>n>>m;
    vector<set<int>>vs(n);
    for(i=0;i<n;i++){
        vector<int>c(m);
        v.pb(c);
        set<int>s1;
        for(j=0;j<m;j++){
            cin>>v[i][j];
            if(primes.find(v[i][j])!=primes.end()){
                s1.insert(v[i][j]);
            }
        }
        vs[i]=(s1);
        // for(auto it:s1){
        //     m1[it]++;
        // }
    }
    ll sum=0;
    vector<int> c;
    vector<vector<int>>subsequence;
    printSubsequences(prime,0,c,subsequence);
    for(auto it:subsequence){

        ll curr = 0;
        for(auto allSet:vs){
            bool flag = true;
            for(auto currSet:it){
                if(allSet.find(currSet)==allSet.end()){
                    flag = false;
                    break;
                }
            }
            if(flag){
                curr++;
            }
        }
        ll currsum = curr*(curr-1)*(curr-2);
        currsum/=6;
        currsum%=mod;
        if(it.size()%2==0){
            sum-=currsum;
            sum = (mod+sum)%mod;
        }
        else{
            sum+=currsum;
            sum = (sum)%mod;
        }
    }
    cout<<sum<<endl;
    // for(auto it:m1){
    //     if(it.S>=3){
    //         ll val = it.S;
    //         ll curr = (val)*(val-1)*(val-2);
    //         curr/=6;
    //         curr%=mod;
    //         sum+=curr;
    //         sum%=mod;
    //     }
    // }
    //cout<<sum<<endl;



    return 0;
}
