#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    vector<int> arr;

    while(t--)
    {
        // cout<<"Test case "<<<<"\n";
        arr.clear();
        cin>>n;
        while(n>=1){
            // cout<<n<<"\n";
            arr.push_back((n%2));
            n = n/2;
        }
        reverse(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++)
        {
            cout<<arr[i];
        }
        cout<<"\n";
    }
   return 0;
}