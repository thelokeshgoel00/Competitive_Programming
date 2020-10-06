#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t,n;
    long long x;
    cin>>t;
    while(t--)
    {
        long long ans = 0;
        cin>>n>>x;
        std::vector<long long>arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int count1 = 0;
        sort(arr.begin(),arr.end());
        auto it = lower_bound(arr.begin(),arr.end(),x);
        int pos = it - arr.begin();
        if(pos==arr.size())
        {
            cout<<arr.size()<<endl;
        }
        else
        {
            ans += pos;
            while(pos!=arr.size())
            {
                long long temp = ceil((double)arr[pos]/x);
                if(temp==1)
                {
                    ans += 1;
                }
                else
                {
                    if(count1==0)
                    {
                        if(pos>0)
                        {
                            if(2*arr[pos-1]>x)
                            {
                                x = 2*arr[pos-1];
                                temp = ceil((double)arr[pos]/x);
                                if(temp==1)
                                {
                                    ans += 1;
                                }
                                else
                                {
                                    ans = ans + 1 + ceil(log2(temp));
                                }
                            }
                            else
                            {
                                ans = ans + 1 + ceil(log2(temp));    
                            }
                        }
                        else
                        {
                            ans = ans + 1 + ceil(log2(temp));    
                        }
                    }
                    else
                    {
                        ans = ans + 1 + ceil(log2(temp));
                    }
                }
                x = 2*arr[pos];    
                pos++;
                count1++;
            }
            cout<<ans<<endl;
        }
    }
}
