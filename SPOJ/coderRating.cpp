#include <bits/stdc++.h>
using namespace std;

struct coder
{
    int x, y, index;//x,y for the rating and index for the  original index.
};
int bit[100001];//finwink tree arrray 10^5 +1

void update(int y)//updating he finwick tree on the base of y rating.
{

    for (; y <= 100000; y += y & (-y))
    {
        bit[y]++;
    }
}

int query(int y)//query for the checking how many have less rating.
{
    int value = 0;
    for (; y > 0; y -= y & (-y))
    {
        value += bit[y];
    }
    return value;
}
bool operator<(coder A, coder B)//overloaded compare function.
{
    if (A.x == B.x)
    {
        return A.y < B.y;
    }
    return A.x < B.x;
}
int main()
{

    int n;
    cin >> n;
    coder arr[n];//coder array.

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].x >> arr[i].y;
        arr[i].index = i;
    }

    sort(arr, arr + n);//sorting on the base of the x.
    int ans[n];//answer stored in the array.

    for (int i = 0; i < n;)
    {
        int endIndex = i;
        //checking for those  whose x and y is same and doing same work for them.
        while (endIndex < n && arr[endIndex].x == arr[i].x && arr[endIndex].y == arr[i].y)
        {
            endIndex++;
        }
        // query

        for (int j = i; j < endIndex; j++)
        {
            ans[arr[j].index] = query(arr[j].y);
        }
        //updating the coder raging for the y.
        for (int j = i; j < endIndex; j++)
        {
            update(arr[j].y);
        }

        i = endIndex;//updating the i.

        // update
    }
    //printing the answer.
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}