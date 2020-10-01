#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define itr(i,n) for(ll i=0 ; i<n ; i++)
#define vi vector<ll>v
#define endl '\n'
//#define M 1000000007
//#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//#define omset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(NULL);ios_base::sync_with_stdio(false);cout.tie(NULL);

using namespace std;
//using namespace __gnu_pbds;

void multiply(ll a[2][2] , ll b[2][2]) {
    ll res[2][2];
    for(int i=0 ; i<2 ; i++) { 
        for(int j=0 ; j<2 ; j++) { 
            res[i][j] = 0; 
            for(int k=0 ; k<2 ; k++) 
                res[i][j] += (a[i][k]*b[k][j])%10; 
        } 
    }
    for(int i=0 ; i<2 ; i++) {
        for(int j=0 ; j<2 ; j++) {
            a[i][j] = res[i][j];
        }
    }
}

ll power(ll F[2][2], ll n) { 
    ll M[2][2] = {{1,1}, {1,0}}; 
    //if(n == 0)
      //  return 0;
    if(n == 1) 
        return F[0][0]; 
  
    power(F, n/2); 
  
    multiply(F, F); 
  
    if (n%2 != 0) 
        multiply(F, M); 
   
    return F[0][0]; 
}

int main() {

    fastio

    ll t;
    cin>>t;

    while(t--) {

        ll n;
        cin>>n;
        
        if(n == 1) {
            cout<<0<<endl;
            continue;
        } else if (n == 2 || n == 3) {
            cout<<1<<endl;
            continue;
        }
        int index = -1;
        while(n != 0) {
            n = n>>1;
            index++;
        }
        int fabN = ((ll)pow(2,index))%60;
        ll M[2][2] = {{1 , 1} , {1 , 0}};
        cout<<power(M , fabN-2)%10<<endl;
        
    }
    return 0;
}


