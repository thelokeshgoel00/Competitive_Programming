vector<int> Solution::flip(string A)
{
    vector<int> a(A.size());
    vector<int> result;
    int n = A.size();
    int current = 0;
    int max = INT_MIN;
    int l = 0;
    int r = 0;
    int L = 0;
    int R = 0;

    for (int i = 0; i < n; ++i)
    {
        a[i] = A[i] == '0' ? 1 : -1;
    }

    for (int i = 0; i < n; ++i)
    {
        current += a[i];

        if (current < 0)
        {
            l = i + 1;
            current = 0;
        }
        else if (current > max)
        {
            max = current;
            L = l;
            R = i;
        }
    }

    if (max >= 0)
    {
        result.push_back(L + 1);
        result.push_back(R + 1);
    }

    return result;
}
