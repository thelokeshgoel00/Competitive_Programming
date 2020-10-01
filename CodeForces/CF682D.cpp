/*
	#358(div-2) problem D
	codeforces handle @KingRayuga
	codechef handle @yashraj_016	
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
ll dp[1005][1005][12][2];
string s,t;
int n,m,k;
 
/*THIS PROBLEM IS DONE USING MULTIDIMENSIONAL DP */ 
 
/*if we see carefully this problem is a modification LCS*/ 
 
 
//function for recursion with memoization 
ll solve(ll is,ll it,ll rem,ll cont)
{
	//base condition
    if(is==n || it==m)
    {
        return ((rem==0)?0:INT_MIN);
    }
    if(rem==0)
    {
        return 0;
    }
    
    //if dp is already initialised then we will return it
    if(dp[is][it][rem][cont]!=-1)
    {
        return dp[is][it][rem][cont];
    }
    ll ret = INT_MIN;
    
    if(s[is]==t[it])
    {
    	//so here variable cont show the continuity
		//here we have two choices 1.to take the element and continue with it 2.take the elemnt and don't continue with it
		//so in second contion no. of remaining substring is total_remaining -1  
        ret = max(ret,1+solve(is+1,it+1,rem,1));
        ret = max(ret,1+solve(is+1,it+1,rem-1,0));
    }    
    //as the elements are not equal so the continuity will break
    //if prev. continuity is 1 then no. of remaining substring is total_remaining -1
    //so like LCS we wil make to cases (i+1,j) or (i,j+1)
    ret = max(ret,solve(is+1,it,rem - cont,0));
    ret = max(ret,solve(is,it+1,rem - cont,0));
 
    //cout<<"is and irt"
    return dp[is][it][rem][cont] = ret;
 
}
 
int main(void)
{
    
    cin>>n>>m>>k;
    cin>>s>>t;
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0,k,0)<<endl;
 
    
}
