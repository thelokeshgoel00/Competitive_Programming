/* 
    Link to hackerrank problem: https://www.hackerrank.com/challenges/array-left-rotation/problem
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, d;
    cin>>n>>d;      //n: number of integers, d: number of left rotations
    
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    int temp;
    if(d!=n)        //if(d==n) then final array is same as initial array
        while(d--)
        {
            temp=a[0];
            for(int i=0; i<n-1; i++)       //performing left rotation by 1 unit
                a[i]=a[i+1];
            a[n-1]=temp;
        }

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";

    return 0;
}
