int Solution::repeatedNumber(const vector<int> &A)
{
    int n = A.size();
    int thresh = (int)floor(n / 3.0) + 1;
    int count_1 = 0;
    int count_2 = 0;
    int first = INT_MAX;
    int second = INT_MAX;

    for (int i = 0; i < n; ++i)
    {
        if (first == A[i])
        {
            ++count_1;
        }
        else if (second == A[i])
        {
            ++count_2;
        }
        else if (count_1 == 0)
        {
            ++count_1;
            first = A[i];
        }
        else if (count_2 == 0)
        {
            ++count_2;
            second = A[i];
        }
        else
        {
            --count_1;
            --count_2;
        }
    }

    count_1 = 0;
    count_2 = 0;

    for (int i = 0; i < n; ++i)
    {
        if (A[i] == first)
        {
            ++count_1;
        }
        else if (A[i] == second)
        {
            ++count_2;
        }
    }

    if (count_1 >= thresh)
    {
        return first;
    }
    else if (count_2 >= thresh)
    {
        return second;
    }
    else
    {
        return -1;
    }
}
