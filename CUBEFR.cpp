/*
    author : Supandeep Singh
    codechef handle @supandeep
    codeforces handle @_Shinigami
*/
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <climits>
#define ll long long
#define endl '\n'
#define M 1000000007
//#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//#define omset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(NULL);ios_base::sync_with_stdio(false);cout.tie(NULL);

using namespace std;
using namespace __gnu_pbds;

int const N = 1e6 + 5;
int primeFactor[N];
pair<int , bool> cubeFree[N];

int main() {

	fastio

	ll t;
	cin>>t;
    
    vector<int> prime;

	for(int i=2 ; i<N ; i++) {
        if(primeFactor[i] != 0) continue;
        primeFactor[i] = i;
        prime.push_back(i);
        for(int j=2*i ; j<N ; j+=i) {
            primeFactor[j] = i;
        }
	}

    vector<pair<int , int>> factors[N];

    for(int i=2 ; i<N ; i++) {
        unordered_map<int , int> mp;
        int x = i;
        while(x != 1) {
            mp[primeFactor[x]]++;
            x /= primeFactor[x];
        }
        for(auto v : mp) {
            factors[i].push_back(v);
        }
    }

    cubeFree[1].first = 1;
    cubeFree[1].second = true;
    int k=2;
    for(int i=2 ; i<N ; i++) {
        cubeFree[i].second = false;
        bool check = false;
        for(int j=0 ; j<factors[i].size() ; j++) {
            if(factors[i][j].second >= 3) {
                check = true;
            }
        }
        if(!check) {
            cubeFree[i].first = k;
            cubeFree[i].second = true;
            k++;
        }
    }

	for(int i=1 ; i<=t ; i++) {

        int n;
        cin>>n;

        if(cubeFree[n].second) {
            cout<<"Case "<<i<<": "<<cubeFree[n].first<<endl;
        } else {
            cout<<"Case "<<i<<": "<<"Not Cube Free"<<endl;
        }

	}

	return 0;
}
