void Solution::setZeroes(vector<vector<int>> &A)
{
    int m = A.size();
    int n = A[0].size();
    set<int> rows;
    set<int> cols;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (A[i][j] == 0)
            {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }

    for (set<int>::iterator i = rows.begin(); i != rows.end(); ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            A[*i][j] = 0;
        }
    }

    for (set<int>::iterator i = cols.begin(); i != cols.end(); ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            A[j][*i] = 0;
        }
    }
}
