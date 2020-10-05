vector<vector<int>> Solution::diagonal(vector<vector<int>> &A)
{
    vector<vector<int>> result;
    int n = A.size();
    int row = 0;
    int col = 0;
    int base_row = 0;
    int base_col = 0;

    for (int i = 0; i < (2 * n) - 1; ++i)
    {
        vector<int> subresult;

        row = base_row;
        col = base_col;

        while (row < n && col > -1)
        {
            subresult.push_back(A[row][col]);
            row += 1;
            col -= 1;
        }

        result.push_back(subresult);

        if (base_row == 0 && base_col < n - 1)
        {
            base_col += 1;
        }
        else if (base_col == n - 1)
        {
            base_row += 1;
        }
    }

    return result;
}
