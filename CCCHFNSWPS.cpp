#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long sum = 0;
        long long ans = 0;
        long long min1;
        unordered_map<long long,long long>arrA;
        unordered_map<long long,long long>arrB;
        unordered_map<long long,long long>arr_diff;    
        int k = 0;
        cin>>n;
        long long temp = 0;
        std::vector<long long>unique(2*n+1);
        std::vector<long long>arr_pos(2*n+1); 
        std::vector<long long>arr_neg(2*n+1);
        int k1 = 0;
        int k2 = 0;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            if(i==0)
            {
                min1 = temp;
            }
            else
            {
                min1 = min(min1,temp);
            }
            arrA[temp]++;
            if(arrA[temp]==1)
            {
                unique[k] = temp;
                k++;
            }
        }
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            min1 = min(min1,temp);
            arrB[temp]++;
            if(arrB[temp]==1 && arrA[temp]==0)
            {
                unique[k] = temp;
                k++;
            }
        } 
        unique.resize(k);
        int flag = 0;
        long long diff = 0;
        int pos_start = 0;
        int pos_end = 0;
        int neg_start = 0;
        int neg_end = 0;        
        for(int i=0;i<k;i++)
        {
            diff = arrA[unique[i]] - arrB[unique[i]];
            if(diff%2!=0)
            {
                flag = 1;
                break;
            }
            sum += diff/2;
            if(diff<0)
            {
                arr_neg[k1] = unique[i];
                k1++;
            }
            else if(diff>0)
            {
                arr_pos[k2] = unique[i];
                k2++;
            }
            arr_diff[unique[i]] = diff/2;
        }

        if(flag==1 || sum!=0 )
        {
            std::cout << -1 << std::endl;
            continue;
            
        }
        else
        {
            arr_pos.resize(k2);
            arr_neg.resize(k1);
            sort(arr_pos.begin(),arr_pos.end());
            sort(arr_neg.begin(),arr_neg.end());
            neg_end = k1 - 1;
            pos_end = k2 - 1;

            
            while(pos_end>=pos_start && neg_end>=neg_start)
            {
                if(arr_pos[pos_start]<=arr_neg[neg_start])
                {
                    if(2*min1<arr_pos[pos_start])
                    {
                        ans += 2*min1*abs(arr_diff[arr_pos[pos_start]]);
                    }
                    else
                    {
                        ans += arr_pos[pos_start]*abs(arr_diff[arr_pos[pos_start]]);
                    }
                    temp = arr_diff[arr_pos[pos_start]] + arr_diff[arr_neg[neg_end]];
                    arr_diff[arr_pos[pos_start]] = temp;
                    while(temp>0)
                    {
                        neg_end--;
                        temp = arr_diff[arr_pos[pos_start]] + arr_diff[arr_neg[neg_end]];
                        arr_diff[arr_pos[pos_start]] = temp;
                    }
                    if(temp==0)
                    {
                        neg_end--;
                    }
                    else if(temp<0)
                    {
                        arr_diff[arr_neg[neg_end]] = temp;
                    }
                    pos_start++;
                }
                else
                {
                    if(2*min1<arr_neg[neg_start])
                    {
                        ans += 2*min1*abs(arr_diff[arr_neg[neg_start]]);
                    }
                    else
                    {
                        ans += arr_neg[neg_start]*abs(arr_diff[arr_neg[neg_start]]);
                    }
                    temp = arr_diff[arr_neg[neg_start]] + arr_diff[arr_pos[pos_end]];

                    arr_diff[arr_neg[neg_start]] = temp;
                    while(temp<0)
                    {
                        pos_end--;
                        temp = arr_diff[arr_neg[neg_start]] + arr_diff[arr_pos[pos_end]];

                        arr_diff[arr_neg[neg_start]] = temp;
                    }
                    if(temp==0)
                    {
                        pos_end--;
                    }
                    else if(temp>0)
                    {
                        arr_diff[arr_pos[pos_end]] = temp;
                    }
                    neg_start++;                    
                    
                }

            }
            cout<<ans<<endl;
        }
        
        
        
    }
}




