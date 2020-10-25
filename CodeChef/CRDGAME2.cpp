#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int m=1000000007;

long long int power(long long int x, long long int y, long long int p)
{
    long long int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
long long int modInverse(long long int n,long long int p)
{
    return power(n, p - 2, p);
}
long long int nCrModPFermat(long long int n,long long int r,long long int p)
{

    if (r == 0)
        return 1;

    long long int fac[n + 1];
    fac[0] = 1;
    for (long long int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long int t,n,c,maxc,count,i,temp,ans,ans2,ans3;
    cin>>t;
    while(t--)
    {
        cin>>n;
        count=0;
        maxc=0;
        for (i=0;i<n;i++){
            cin>>c;
            if (c==maxc)
                count++;
            else if (c>maxc){
                maxc=c;
                count=1;
            }
        }
        ans2=0;
        if (count%2==0)
        {
            temp=n-count;
            ans3=power(2,temp,m);
            ans2=nCrModPFermat(count,count/2,m);
            ans2*=ans3;
            ans2%=m;
        }
        temp=n;
        ans=power(2,temp,m);
        ans-=ans2;
        ans=(ans+m)%m;
        cout<<ans<<"\n";
    }

    return 0;
}
