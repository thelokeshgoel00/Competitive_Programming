/*
	August long challenge problem 4
	codechef handle @yashraj_016
	codeforces handle @KingRayuga
*/




#include<bits/stdc++.h>
using namespace std;
#define int long long 

//Function for calculating no. of triangle form n lines
//time complexity O(nlong)
//if you want detailed description of this function visit here -> 'https://www.geeksforgeeks.org/number-triangles-can-formed-given-set-lines-euclidean-plane/'
int find_active_triangle(unordered_map<int,vector<int>>l1,int color,int lines)
{
    vector<int>l = l1[color];
    //cout<<"size of l is "<<l.size()<<endl;
    int temp = 0;
    for(int i=0;i<l.size();i++)
    {
        if(lines<0)
        {
            break;
        }
        temp = min(l[i],lines);
        l[i] = l[i] - temp;
        lines = lines - temp;
    }
    if(lines>0)
    {
        return 0;
    }
    int sum1 = 0; 
    int k = l.size();
    for (int i=0; i<k; i++)
    {
        sum1 += l[i];
    }
    //cout<<"sum1 is "<<sum1<<endl;
    int sum2 = 0; 
    int count1[k+1];  
    for (int i=0; i<k; i++) 
    { 
        count1[i] = l[i]*(sum1-l[i]); 
        sum2 += count1[i]; 
    } 
    sum2 =sum2/2; 
    //cout<<"sum2 is "<<sum2<<endl;
    int sum3 = 0; 
    for (int i=0; i<k; i++)
    {
        sum3 += l[i]*(sum2-count1[i]);
    }
    sum3 =sum3/3; 
    //cout<<"sum3 is "<<sum3<<endl;
    return sum3;    
}

signed main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c,k,a,b,col;
        cin>>n>>c>>k;
        int v[c+11];
        int arr[n+11];
        int dp[k+3][c+3];
        unordered_map<int,int>mp1[c+11];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i]>>b>>col;
            mp1[col][arr[i]]++;
        }
        for(int i=1;i<=c;i++)
        {
            cin>>v[i];
        }
        //so what we will do here is that we map all the vector from a map instead of creating vector<vector<int>>
        //to meet our desired need
        unordered_map<int,vector<int>>l;
        for(int i=1;i<=c;i++)
        {
            for(auto x:mp1[i])
            {
                l[i].push_back(x.second);
            }
            sort(l[i].begin(),l[i].end());
        }
        //base condition of DP
        for(int i=0;i<=k;i++)
        {
            for(int j=0;j<=c;j++)
            {
                if(j==0)
                {
                    dp[i][j]=0;
                }
                else
                {
                    dp[i][j] = INT_MAX;
                }
            }
        }
        //So this is our dp relation to calcute the max no. of activated triangles
        for(int i=0;i<=k;i++)
        {
            for(int j=1;j<=c;j++)
            {
                for(int z = 0; z<=(i/v[j]) ;z++)
                {
                    //cout<<"z*v[j] is "<<z*v[j]<<endl;
                    //cout<<"before operation dp[i][j] is "<<dp[i][j]<<endl;
                    dp[i][j] = min(dp[i][j],dp[i - z*v[j]][j-1] + find_active_triangle(l,j,z));
                    //cout<<"i j and dp is "<<i<<" "<<j<<" "<<dp[i][j]<<endl;
                }
            }
        }
        cout<<dp[k][c]<<endl;
    }
}
