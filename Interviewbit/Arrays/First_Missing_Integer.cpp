int Solution::firstMissingPositive(vector<int> &A)
{
    int n = A.size();
    int c = 0;
    int temp = 0;
    int index = 0;
    int N = 0;

    for (int i = 0; i < n; ++i)
    {
        if (A[i] < 0)
        {
            temp = A[i];
            A[i] = A[c];
            A[c++] = temp;
        }
    }

    N = (n - c);
    for (int i = 0; i < N; ++i)
    {
        index = abs(A[i + c]) - 1;
        if (index < N && A[index + c] > 0)
        {
            A[index + c] *= -1;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        if (A[i + c] > 0)
        {
            return i + 1;
        }
    }

    return N + 1;
}