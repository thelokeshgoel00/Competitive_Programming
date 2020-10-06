vector<int> Solution::getRow(int A)
{
    vector<vector<int>> result;
    int n = 0;
    int m = 0;

    for (int i = 0; i <= A; ++i)
    {
        vector<int> subresult;

        if (i == 0)
        {
            subresult.push_back(1);
            result.push_back(subresult);
            continue;
        }

        n = result.size();
        m = result[n - 1].size();
        for (int j = 0; j < i + 1; ++j)
        {
            if (j == 0)
            {
                subresult.push_back(1);
            }
            else if (j > 0 && j < m)
            {
                subresult.push_back(result[n - 1][j - 1] + result[n - 1][j]);
            }
            else if (j == m)
            {
                subresult.push_back(result[n - 1][j - 1] + 0);
            }
        }

        result.push_back(subresult);
    }

    return result[A];
}
