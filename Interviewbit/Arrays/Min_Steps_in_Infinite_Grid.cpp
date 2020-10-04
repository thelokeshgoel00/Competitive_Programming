int Solution::coverPoints(vector<int> &A, vector<int> &B)
{
    long int x = A[0];
    long int y = B[0];
    long int steps = 0;
    long int x_diff = 0;
    long int y_diff = 0;

    for (long int i = 1; i < A.size(); ++i)
    {
        x_diff = A[i] - x;
        y_diff = B[i] - y;

        steps += min(abs(x_diff), abs(y_diff)) + abs(abs(x_diff) - abs(y_diff));

        x = A[i];
        y = B[i];
    }

    return steps;
}
