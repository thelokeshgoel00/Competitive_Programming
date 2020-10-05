vector<int> Solution::nextPermutation(vector<int> &A)
{
    int n = A.size();
    int c = -1;
    int index = 0;
    int temp = 0;

    for (int i = n - 1; i > 0; --i)
    {
        if (A[i] > A[i - 1])
        {
            c = i;
            break;
        }
    }

    if (c == -1)
    {
        sort(A.begin(), A.end());
        return A;
    }

    vector<int>::iterator upper;

    sort(A.begin() + c, A.end());

    upper = upper_bound(A.begin() + c, A.end(), A[c - 1]);
    index = upper - A.begin();

    temp = A[index];
    A[index] = A[c - 1];
    A[c - 1] = temp;

    return A;
}
