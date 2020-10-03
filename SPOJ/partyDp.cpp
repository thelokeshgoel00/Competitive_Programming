
//   https://www.spoj.com/problems/PARTY/
//  PARTY - Party Schedule
// solution using dynamic programming.

#include <bits/stdc++.h>
using namespace std;

void knapsack(int *cost, int *fun, int n, int budjet)
{

    int *dp = new int[budjet + 1];//reduce the space complexity only 2xn dp used.
    int *predp = new int[budjet + 1];
    
    //initialization of the dp
    for (int i = 0; i <= budjet; i++)
    {
        dp[i] = 0;
        predp[i]= 0;
    }

    for (int i = 1; i <= n; i++)
    {//every time checking if max weight is j

        for (int j = 1; j <= budjet; j++)
        {
            if (cost[i - 1] > j)//
            {
                // if weight of the element is more than required weight then give previous value.
                dp[j] = predp[j];
                
            }
            else
            { // else assign the maximum of the previous of the fun plus that index
                if(predp[j]<(fun[i-1]+predp[j-cost[i-1]]))
                {
                    dp[j] = fun[i - 1] + predp[j - cost[i - 1]];
                    
                }
                
                else 
                {
                    dp[j] = predp[j];
                    
                }
            }
        }

        for (int j = 0; j <= budjet; j++)
        {
            predp[j] = dp[j];//copying the dp into pre dp
            
        }
    }

    //iterating until we get the unequal value.
    int i=budjet;
    while(i&&predp[i]==predp[i-1])
    {
        i--;

    }
    cout<<i<<" ";
    int ans=predp[budjet];
    delete[]dp;
    delete []predp;
    cout<<ans<<endl;
    

}
//driver code.
int main()
{	

    int n,m;
    while(1)
    {
        cin >> m >> n ;
        if(m==0&&n==0)
        break;
     
       int *cost = new int[n];
        int *fun = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> cost[i] >> fun[i];
        }
        knapsack(cost, fun, n, m);
    }

    return 0;
}