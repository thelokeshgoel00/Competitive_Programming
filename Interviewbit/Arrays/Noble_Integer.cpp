int Solution::solve(vector<int> &A)
{
    sort(A.begin(), A.end());
    int n = A.size();
    int flag = -1;

    for (int i = 0; i < n; ++i)
    {
        if (i < n - 1 && A[i] == A[i + 1])
        {
            continue;
        }
        else
        {
            if (n - 1 - i == A[i])
            {
                flag = 1;
                break;
            }
        }
    }

    return flag;
}
