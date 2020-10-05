#include <bits/stdc++.h>
using namespace std;

struct coder
{
    int first, second, index;//start end  and the original index.
} query[200000];

bool operator<(coder A, coder B)//comprator used to sort according to the end.
{

    return A.second < B.second;
}

int bit[30001];//binary index tree.
//update the binary index tree.
void update(int index, int value, int n)
{

    for (; index <= n; index += index & (-index))
    {
        bit[index] += value;
    }
}
int last[1000001];//hash map to check for the previous occurance.
int arr[30001];//array for the input.

// query for the value .
int value(int index)
{

    int res = 0;
    for (; index > 0; index -= index & (-index))
    {
        res += bit[index];
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    //array indexing start from 1 to n
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int q;
    cin >> q;
    //input of the query
    for (int i = 0; i < q; i++)
    {
        cin >> query[i].first >> query[i].second;
        query[i].index = i;
    }

    sort(query, query + q);//sorting the queries according the last index query.

    memset(last, -1, sizeof(last));

    int k = 0;
    int ans[q];

    int total = 0;
    for (int i = 1; i <= n; i++)
    {

        if (last[arr[i]] != -1)//if element already present.
        {
            update(last[arr[i]], -1, n);//change contribution to -1 
        }
        else
        {
            total++;
        }

        update(i, 1, n);//update 1 contribution for the index i
        last[arr[i]] = i;

        while (k < q && query[k].second == i)//solving the  query for those whose last index is i
        {

            ans[query[k].index] = total - value(query[k].first - 1);//current total - the first index value.
            k++;
        }
    }
    //displaying the ans.
    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}