#include<bits/stdc++.h>
using namespace std;
long saveEnergy( long *arr, long n){
	long ans = 0;
	long i = 0;
	long j = -;

	while( i < n-1){
		j = i + 1;
			while( j < n-1){
				if( abs(arr[i]) > abs(arr[j])  || (abs(arr[i]) == abs(arr[j]) && arr[i] > 0)){
					break;
				}else{
					j++;
				}
		}

		ans += (j - i)*arr[i] + (j*j - i*i)*arr[i]*arr[i];
		i = j;
	}

	return ans;
}
int main(){
	long  n;
	cin >> n;
	long *arr = new long[n];
	for(long i = 0; i < n; i++)
		cin >> arr[i];
	long ans = saveEnergy(arr, n);
	cout << ans;
	return 0;
}






















#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
struct item
{
    ll start,end,cost;
    item(){}
    item(ll a,ll b,ll c)
    {
        start = a;
        end = b;
        cost = c;
    }
};

ll max(ll a,ll b)
{
    return a>b?a:b;
}

bool sortbyFinal(struct item a,struct item b)
{
    return a.end<b.end;
}

ll binary(item * v,ll index)
{
    ll lo = 0;
    ll high = index - 1;

    while(lo<=high)
    {
        ll mid = (lo+high)/2;
        if(v[mid].end <=  v[index].start)
        {
            if(v[mid+1].end <= v[index].start)
            {
                lo = mid+1;
            }
            else
            {
                return mid;
            }
        }
        else
        {
            high = mid-1;
        }
    }
    return -1;
}

int main()
{
    ll n;
    cin>>n;
    item *v = new item[n];
    for(ll i=0;i<n;i++)
    {
        ll start,end,prof;
        cin>>start>>end>>prof;
        v[i] = (item(start,end,prof));
    }

    sort(v,v+n,sortbyFinal);

// for(int i=0;i<n;i++)
// {
//     cout<<v[i].start<<" "<<v[i].end<<endl;
// }

    ll arr[n];
    arr[0] = v[0].cost;

    for(ll i=1;i<n;i++)
    {
        // int j=i-1;
        // while(j>=0)
        // {
        //     if(v[j].end <= v[i].start)
        //     {
        //         break;
        //     }
        //     j--;
        // }
        ll temp = v[i].cost;
        ll index = binary(v,i);
        if(index!=-1)
        {
            temp += arr[index];
        }
        arr[i] = max(temp,arr[i-1]);
    }

    // for(int i=0;i<n;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    cout<<arr[n-1]<<endl;
}
