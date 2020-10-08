vector<int> Solution::solve(vector<int> &A)
{
    vector<int> result;
    long int n = A.size();

    int zero_start = -1;
    int zero_end = -1;

    int neg_pointer = -1;
    int pos_pointer = -1;

    bool negative_exists = false;
    bool positive_exists = false;

    if (A[0] < 0)
    {
        negative_exists = true;
    }

    for (int i = 0; i < n; ++i)
    {
        if (A[i] == 0)
        {
            if (zero_start == -1)
            {
                zero_start = i;
            }
            zero_end = i;
        }

        if (A[i] > 0)
        {
            positive_exists = true;
            pos_pointer = i;
            break;
        }
    }

    if (negative_exists == false)
    {
        for (int i = 0; i < n; ++i)
        {
            result.push_back(A[i] * A[i]);
        }
    }
    else if (positive_exists == false)
    {
        for (int i = n - 1; i >= 0; --i)
        {
            result.push_back(A[i] * A[i]);
        }
    }
    else
    {
        if (zero_start == -1)
        {
            neg_pointer = pos_pointer - 1;
        }
        else
        {
            neg_pointer = zero_start - 1;
            pos_pointer = zero_end + 1;

            for (int i = zero_start; i <= zero_end; ++i)
            {
                result.push_back(0);
            }
        }

        while (neg_pointer >= 0 && pos_pointer < n)
        {
            if (abs(A[neg_pointer]) < abs(A[pos_pointer]))
            {
                result.push_back(A[neg_pointer] * A[neg_pointer]);
                --neg_pointer;
            }
            else
            {
                result.push_back(A[pos_pointer] * A[pos_pointer]);
                ++pos_pointer;
            }
        }

        while (neg_pointer >= 0)
        {
            result.push_back(A[neg_pointer] * A[neg_pointer]);
            --neg_pointer;
        }

        while (pos_pointer < n)
        {
            result.push_back(A[pos_pointer] * A[pos_pointer]);
            ++pos_pointer;
        }
    }

    return result;
}
