vector<int> Solution::findPerm(const string A, int B)
{
    vector<int> natural;
    vector<int> result;
    int max_val = B;
    int min_val = 1;

    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] == 'I')
        {
            result.push_back(min_val);
            ++min_val;
        }
        else if (A[i] == 'D')
        {
            result.push_back(max_val);
            --max_val;
        }
    }

    result.push_back(min_val);

    return result;
}
