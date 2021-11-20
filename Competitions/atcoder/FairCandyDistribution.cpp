#include <bits/stdc++.h>
using namespace std;

bool sort_by_value(pair<long long int, long long int> a, pair<long long int, long long int> b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    long long int n, k;
    cin >> n;
    cin >> k;
    map<long long int, long long int> ids;
    for (long long int i = 1; i < n + 1; i++)
    {
        cin >> ids[i];
    }
    vector<pair<long long int, long long int>> IDs(ids.begin(), ids.end());
    sort(IDs.begin(), IDs.end(), sort_by_value);
    vector<long long int> result;
    if (k >= n)
    {
        long long int number = k / n;
        result = vector<long long int>(n, number);
        k -= n * number;
        for (auto i = IDs.begin(); i != IDs.end() && k > 0; i++)
        {
            result[(*i).first - 1] += 1;
            k--;
        }
    }
    else
    {
        result = vector<long long int>(n, 0);
        for (auto i = IDs.begin(); i != IDs.end() && k > 0; i++)
        {
            result[(*i).first - 1] += 1;
            k--;
        }
    }

    for (auto i = result.begin(); i != result.end(); i++)
        cout << (*i) << endl;

    return 0;
}