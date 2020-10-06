vector<int> Solution::wave(vector<int> &A)
{
    vector<int> result;
    int n = A.size();

    sort(A.begin(), A.end());

    for (int i = 1; i < n; i += 2)
    {
        result.push_back(A[i]);
        result.push_back(A[i - 1]);
    }

    if (result.size() != n)
    {
        result.push_back(A[n - 1]);
    }

    return result;
}
