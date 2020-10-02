#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long n;
    int t;
    cin>>t;
    while(t--)
    {
        int count1 = 0;
        cin>>n;
        n = 4*n-1;
        long long ans_x = 0;
        long long ans_y = 0;
        while(n--)
        {
            long long x,y;
            cin>>x;
            cin>>y;
            ans_x = ans_x^x;
            ans_y = ans_y^y;
        }
        cout<<ans_x<<" "<<ans_y<<endl;
    }
}
