vector<int> Solution::subUnsort(vector<int> &A)
{
    vector<int> result;

    int l = INT_MAX;
    int r = INT_MIN;
    int index = 0;

    int minimum = INT_MAX;
    int maximum = INT_MIN;

    vector<int>::iterator lower;

    for (int i = 0; i < A.size(); ++i)
    {
        if (i > 0)
        {
            if (A[i] < A[i - 1])
            {
                if (l == INT_MAX || A[i] < minimum)
                {
                    lower = lower_bound(A.begin(), A.begin() + i, A[i]);
                    index = lower - A.begin();

                    if (index < i)
                    {
                        while (A[index] == A[i])
                        {
                            ++index;
                        }

                        l = min(l, index);
                        r = i;
                    }
                }
                else if (A[i - 1] > maximum)
                {
                    r = i;
                }

                minimum = min(minimum, A[i]);
                maximum = max(maximum, A[i - 1]);
            }

            if ((A[i] == A[i - 1] && r == i - 1) || (A[i] < maximum))
            {
                r = i;
            }
        }
    }

    if (l == INT_MAX)
    {
        result.push_back(-1);
    }
    else
    {
        result.push_back(l);
        result.push_back(r);
    }

    return result;
}
