/*
	round-673 div-2 D
	codeforces handle @KingRayuga
	codechef handle @yashraj_016
*/

#include<bits/stdc++.h>
using namespace std;
 
/*
	We will aproach greedily to this problem
	As the overall change is zero in this process 
	so we can make the element equal if and only if total_sum is divisible by n
	the approach we will use ,uses at most 3*(n-3) steps
	so what we will do we transfer all the value to a1 which take atmost 2 steps
	because from a1 it is easy to distribute the sum/n to all the value
	as i  = 1
*/ 
 
int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+2];
        long long sum = 0;
        //take inout and calculate sum
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        if(sum%n==0)
        {
            for(int i=2;i<=n;i++)
            {
                if(arr[i]%i!=0)
                {
                	//if arr[i] is not divisible by i we will give some value from a1 to ai,it can be proofed it is always possible
                    int temp = i - arr[i]%i;
                    cout<<1<<" "<<i<<" "<<temp<<endl;
                    arr[i] = arr[i] + temp;
                }
                //here we transfer value of a[i] to a[1]
                int res = arr[i]/i;
                cout<<i<<" "<<1<<" "<<res<<endl;
            }
            int divK = sum/n;
            for(int i=2;i<=n;i++)
            {
             	//and here we distribute the sum to all the cells from 2 to n   
                cout<<1<<" "<<i<<" "<<divK<<endl;
            }
        }
        else
        {
            cout<<-1<<endl;
        }
    }
}
