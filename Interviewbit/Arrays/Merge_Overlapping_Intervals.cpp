/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool compare_function(Interval a, Interval b)
{
    return a.start < b.start;
}

vector<Interval> Solution::merge(vector<Interval> &A)
{
    int n = A.size();
    int start = A[0].start;
    int end = A[0].end;
    vector<Interval> intervals;

    sort(A.begin(), A.end(), compare_function);

    for (int i = 0; i < n; ++i)
    {
        cout << A[i].start << " " << A[i].end << endl;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        if (end >= A[i + 1].start)
        {
            start = min(start, A[i + 1].start);
            end = max(end, A[i + 1].end);
        }
        else
        {
            intervals.push_back(Interval(start, end));
            start = A[i + 1].start;
            end = A[i + 1].end;
        }
    }

    intervals.push_back(Interval(start, end));

    return intervals;
}
