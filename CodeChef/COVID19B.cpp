#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);;
    cin.tie(NULL);
    cout.tie(NULL);
    long long int t,n,i,s,j,mi,ma,c,maxs,mins;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long int v[n],arr[n][n];
        for(i=0;i<n;i++)
        {
            cin>>v[i];
        }
        for (i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                arr[i][j]=0;
            }
        }
        maxs=v[0];
        for (i=0;i<n;i++)
        {
            arr[i][i]=1;
            if (maxs<v[i])
                maxs=v[i];
            for(j=0;j<n;j++)
            {
                if (j>i && v[j]<maxs)
                    arr[i][j]=1;
                else if (i>j && v[j]>v[i])
                    arr[i][j]=1;
            }
        }
        for (i=0;i<n;i++)
        {
            mins=6;
            for (j=n-1;j>=0;j--)
            {
                if (j>=i && arr[i][j]==1 && v[j]<mins)
                    mins=v[j];
                else if (j<i && v[j]>mins)
                    arr[i][j]=1;
            }
        }
        /*for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
                cout<<arr[i][j]<<" ";
            cout<<"\n";
        }*/
        mi=n+1;
        ma=0;
        for (i=0;i<n;i++)
        {
            c=0;
            for(j=0;j<n;j++)
            {
                if(arr[i][j])
                    c++;
            }
            if(c>ma)
                ma=c;
            if(c<mi)
                mi=c;
        }
        cout<<mi<<" "<<ma<<"\n";
    }
    return 0;
}
