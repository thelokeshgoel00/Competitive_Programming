int Solution::maximumGap(const vector<int> &A)
{
    int result = -1;
    int n = A.size();
    int l = 0;
    int r = 0;

    vector<int> L(n, 0);
    vector<int> R(n, 0);

    L[0] = A[0];
    for (int i = 1; i < n; ++i)
    {
        L[i] = min(A[i], L[i - 1]);
    }

    R[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        R[i] = max(A[i], R[i + 1]);
    }

    while (l < n && r < n)
    {
        if (L[l] < R[r])
        {
            result = max(result, r - l);
            ++r;
        }
        else
        {
            ++l;
        }
    }

    return result;
}
