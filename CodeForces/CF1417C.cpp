/*
	round-673 div-2 C
	codeforces handle @KingRayuga
	codechef handle @yashraj_016
*/

#include<bits/stdc++.h>
using namespace std;
 
/*
	the approach here is to use the spacing frequency of the each elements
	and acc. to frequency of spacing we will choose the smallest one
	and answer accordingly for each subset
*/ 
 
int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+2] = {0};
        int index[n+2] = {0};
        int ans[n+2] = {0};
        int freq[n+2] = {0};
        //initializtion of array
        for(int i=0;i<=n;i++)
        {
            ans[i] = n+1;
            index[i] = 0;
            freq[i] = 0;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
            
            //the index array show previous index of arr[i]
            if(index[arr[i]]==0)
                freq[arr[i]] = max(i,freq[arr[i]]);//calculation of frequency from starting point
            else
                freq[arr[i]] = max(i - index[arr[i]],freq[arr[i]]);//calculation of frequency in between the array
            index[arr[i]] = i;
        }
        for(int i=1;i<=n;i++)
        {
            
            freq[arr[i]] = max(n - index[arr[i]] + 1,freq[arr[i]]);//calculation of frequency from last
            index[arr[i]] = n;
        }
        for(int i=1;i<=n;i++)
        {
            //cout<<"i and freq of i is "<<i<<" "<<freq[i]<<endl;
            ans[freq[i]] = min(ans[freq[i]],i);
            
        }
        //calculating value of answer
        if(ans[1]!=n+1)
        {
            std::cout << ans[1] << " ";
        }
        else
        {
            cout<<-1<<" ";
        }
        for(int i=2;i<=n;i++)
        {
        	//here ans[i] also depend on previous values 
            ans[i] = min(ans[i],ans[i-1]);
            if(ans[i]!=n+1)
            {
                cout<<ans[i]<<" ";
            }
            else
            {
                cout<<-1<<" ";
            }
        }
        cout<<endl;
        
    }
}
