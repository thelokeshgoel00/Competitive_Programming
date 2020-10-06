int Solution::solve(vector<string> &A)
{
    vector<double> a;
    int n = A.size();

    for (int i = 0; i < n; ++i)
    {
        a.push_back(stof(A[i]));
    }

    double x = 0;
    double y = 0;
    double z = 0;
    double sum = 0;

    x = a[0];
    y = a[1];
    z = a[2];

    for (int i = 3; i < n; ++i)
    {
        sum = x + y + z;

        if (sum > 1 && sum < 2)
        {
            return 1;
        }
        else if (sum > 2)
        {
            if (x > y && x > z)
            {
                x = a[i];
            }
            else if (y > x && y > z)
            {
                y = a[i];
            }
            else
            {
                z = a[i];
            }
        }
        else
        {
            if (x < y && x < z)
            {
                x = a[i];
            }
            else if (y < x && y < z)
            {
                y = a[i];
            }
            else
            {
                z = a[i];
            }
        }
    }

    sum = x + y + z;

    if (sum > 1 && sum < 2)
    {
        return 1;
    }

    return 0;
}
