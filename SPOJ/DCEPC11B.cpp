#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll power(ll a, ll b, ll c){
    ll ans = 1ll;
    while(b>0){
        if(b&1){
            ans = (ans*a)%c;
        }
        a = (a*a)%c;
        b=b>>1;
    }
    return ans;
}
int main(){
    int test;
    std::cin >> test;
    while(test--){
        ll n, p;
        cin >> n >> p;
        if(n>=p){
            cout << 0 << endl;
            continue;
        }
        ll sum = 1;
        for(ll i = n+1; i<p; i++){
            sum = (sum*i)%p;

        }
        ll ans = power(sum, p-2, p);

        cout << p-ans << endl;
    }
}
