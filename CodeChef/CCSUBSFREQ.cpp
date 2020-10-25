/*
	August long challenge problem 3
	codechef handle @yashraj_016
	codeforces handle @KingRayuga
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define mod 1000000007

int fac[500000 + 10];

int mypow(int x,int y,int p)
{
    int res = 1;
    
    x = x % p;
    while (y > 0)
    { 
        if (y & 1) 
            res = (res * x) % p; 
        y = y >> 1;
        x = (x * x) % p; 
    } 
    return res; 
}

int modInverse(int n, int p) 
{ 
    return mypow(n, p - 2,p); 
}

void calcute_factorial()
{
    fac[0] = 1;
    for(int i=1;i<=500001;i++)
    {
        fac[i] = ((fac[i-1]%mod)*(i%mod))%mod;
    }
}

int nCr(int n,int r, int p) 
{
	//this NCR is based on fermat's little theorem
    if (r == 0 || r == n) 
    {
        return 1;
    }
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
} 

signed main(void)
{
    calcute_factorial();
    int t;
    cin>>t;
    //cout<<"factorial of 0 1 and 5 is "<<fac[0]<<" "<<fac[1]<<" "<<fac[5]<<endl;
    while(t--)
    {
        unordered_map<int,int>mp1;
        multiset<int>st1;
        int n;
        cin>>n;
        int arr[n+2];
        int no_at_pos[n+11];
        int no_at_prev_pos[n+11];
        memset(arr,0,sizeof(arr));
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            mp1[arr[i]]++;
        }
        for(int i=1;i<=n+4;i++)
        {
            no_at_pos[i] = 1;
            no_at_prev_pos[i] = 1;
        }
        for(auto x:mp1)
        {
            st1.insert(x.second);
        }
        int prev = 1;
        int curr = 1;
        int prev_val = 1;
        int prev_val_use = 1;
        //HERE we are calculating (1)*(1+xCi)*(1 + xCi + 1+xCi+1).............
        for(auto x:st1)
        {
        	
            int sum=1;
            curr = x;
            //cout<<"x is "<<x<<endl;
            for(int i=1;i<=x;i++)
            {
                sum =(sum%mod + nCr(x,i,mod)%mod)%mod;
                //cout<<"sum and ncr  is "<<sum<<" "<<nCr(x,i,mod)<<endl;
                no_at_pos[i] = ((no_at_pos[i]%mod)*(sum%mod)*(prev_val_use%mod))%mod;
                //cout<<"i sum and no_at_pos is "<<i<<" "<<sum<<" "<<no_at_pos[i]<<endl;
            }
            //cout<<"x and sum is "<<x<<" "<<sum<<endl;
            no_at_prev_pos[x+1] = ((no_at_prev_pos[x+1]%mod)*(sum%mod))%mod; 
        }
        int temp1 = 1;
        for(int i=1;i<=n+4;i++)
        {
            temp1 = ((temp1%mod)*(no_at_prev_pos[i]%mod))%mod;
            //cout<<"temp1 is "<<temp1<<endl;
            no_at_pos[i] = ((no_at_pos[i]%mod)*(temp1%mod))%mod;
        }
        //cout<<"***************"<<endl;
        //cout<<"no_at_pos 6 "<<no_at_pos[6]<<endl;
        int result = 0;
        int count1 = 1;
        while(n--)
        {
            int sum = 1;
            int prev_sum = 1;
            result = 0;
            if(mp1[count1])
            {
                int temp = mp1[count1];
                //Here we are calculating the value for each position
                for(int i=1;i<=temp;i++)
                {
                    int ans = nCr(temp,i,mod);
                    sum = (sum%mod + ans%mod)%mod;
                    no_at_pos[i] = ((no_at_pos[i])*(modInverse(sum,mod)))%mod;
                    ans = ((ans%mod)*(no_at_pos[i]%mod))%mod;
                    no_at_pos[i] = ((no_at_pos[i]%mod)*(prev_sum%mod))%mod;
                    result = (result%mod + ans%mod)%mod;
                    prev_sum = sum;
                }
            }
            std::cout << result << " ";
            count1++;
        }
        cout<<endl;
    }
}
