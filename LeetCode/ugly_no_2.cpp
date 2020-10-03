//I've been expecting you <3
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
vector<int> nthUglyNumber()
{
    map<int, vector<int>> m;
    int ar[8001]={0};
    // cout<<ar[10]<<"2@@"<<endl;
    for (int i = 2; i <= 8000; i++)
    {   
        for (int j = 2 * i; j <= 8000; j+=i)
        {   
            ar[j]=-1;
            if (!ar[i])
            {
                m[j].push_back(i);
            }
        }
    }
    // for(int i=2; i<20; i++){
    //     cout<<m[i].size()<<endl;
    // }
    vector<int> v;
    for (int i = 2; i < 8000; i++)
    {
        if (i > 5 && m[i].size() == 0)
        {
            continue;
        }
        else
        {
            int flag = 1;
            for (int j = 0; j < m[i].size(); j++)
            {
                if (m[i][j] == 2 || m[i][j] == 3 || m[i][j] == 5)
                {
                    flag = 1;
                    // break;
                }
                else{
                    flag=0;
                    break;
                }
            }
            if (flag == 1)
                v.push_back(i);
        }
    }
    return v;
    // if (n == 1){
    //     return 1;
    // }
    // else
    //     return v[n - 1];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> v = nthUglyNumber();
        for (int i = 0; i < 20; i++)
        {
            cout << v[i] << endl;
        }
        // int n;
        // cin>>n;
        // cout<<nthUglyNumber(n)<<endl;
    }
}
