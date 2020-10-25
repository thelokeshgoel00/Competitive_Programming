#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod(ll a, string str, int c){
    ll ans = 1ll;
    for(int i = str.length()-1; i>=0; i--){
        if(str[i]=='1'){
            ans = (ans*a)%c;
        }else if(str[i]=='2'){
            ans = (((ans*a)%c)*a)%c;
        }
        a = (((a*a)%c)*a)%c;
    }
    return ans;
}
int main(){
    int test;
    cin >> test;
    while(test--){
        ll a;
        int c;
        string b;
        cin >> a >> b >> c;
        ll ans = mod(a, b, c);
        cout << ans << endl;
    }
}
