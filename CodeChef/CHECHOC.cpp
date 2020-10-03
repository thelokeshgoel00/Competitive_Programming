/******************************************
* AUTHOR : PRIYAM THAKURIA*
* NICK : psiphon_hack *
* INSTITUTION : NIT Kurukshetra *
******************************************/
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

ll test_case()
{
	ll n,m,x,y; cin>>n>>m>>x>>y;
    if(m==1 && n==1) 
    return x;
    if((m*n)%2==0) {
        if((y/2) >= x) 
            return (x*m*n);
        else
            return ((y*m*n)/2);
    }
    else {
        //cout<<"i am here\n";
        if((y/2) >= x) 
            return (x*m*n);
        else {
            ll no=(n*m)-1;
            no/=2;
            ll big=y/2 +1;
            //cout<<no<<" "<<big<<"\n";
            if(x>y)
                return ((no*y) + y);
            else
                return ((no*y) + x);
        }
    }
}

int main() {

	fastio
	ll t; cin >> t;
	while (t--)
		cout<<test_case()<<"\n";

	return 0;
}
