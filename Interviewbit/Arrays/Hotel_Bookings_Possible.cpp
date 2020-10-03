bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.first < b.first);
}

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K)
{
    vector<pair<int, int>> paired;
    vector<int> arrival;
    vector<int> departure;

    int n = arrive.size();
    int arrive_index = 0;
    int depart_index = 0;
    int available = K;

    const int arrive_const = 0;
    const int depart_const = 1;

    for (int i = 0; i < n; ++i)
    {
        paired.push_back(make_pair(depart[i], depart_const));
        paired.push_back(make_pair(arrive[i], arrive_const));
    }

    sort(paired.begin(), paired.end(), comp);

    for (int i = 0; i < paired.size(); ++i)
    {
        if (paired[i].second == arrive_const)
        {
            --available;
        }
        else if (paired[i].second == depart_const)
        {
            ++available;
        }

        if (available < 0 && i < paired.size() - 1 && paired[i].first < paired[i + 1].first)
        {
            return 0;
        }
        else if (available < 0 && i == paired.size() - 1)
        {
            return 0;
        }

        available = min(available, K);
    }

    return 1;
}