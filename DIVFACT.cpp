#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define endl '\n'
#define M 1000000007
//#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//#define omset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(NULL);ios_base::sync_with_stdio(false);cout.tie(NULL);

using namespace std;
//using namespace __gnu_pbds;

const int N = 500005;
int composite[N];

using namespace std;

int power(int x, unsigned int y) { 
    int res = 1;     // Initialize result 
   
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = res*x; 
   
        // y must be even now 
        y = y>>1; // y = y/2 
        x = x*x;  // Change x to x^2 
    } 
    return res; 
}

int main() {

    fastio

    vector<int> prime;

    for(int i=2 ; i<N ; i++) {
        if(composite[i])
            continue;
        prime.push_back(i);
        for(int j=2*i ; j<N ; j+=i) {
            composite[j] = 1;
        }
    }

    ll t;
    cin>>t;

    while(t--) {

        ll n;
        cin>>n;

        ll res = 1;

        for(int i=0 ; i<prime.size() && prime[i] <= n ; i++) {
            ll temp = 0;
            for(int j=1 ; n/power(prime[i],j) != 0 ; j++) {
                temp = (temp + (ll)n/(ll)power(prime[i],j)) % M;
            }
            res = (res*(temp + 1)) % M;
        }

        cout<<res%M<<endl;

    }

}
